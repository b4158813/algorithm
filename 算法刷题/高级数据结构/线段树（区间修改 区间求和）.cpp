#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
struct Stree{
	ll l,r,sum,lz;
}tree[4*N];
ll n,q,a[N];
void build(ll i,ll l,ll r){
	tree[i].l=l,tree[i].r=r;
	if(l==r){
		tree[i].sum=a[l];
		return;
	}
	ll mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
}

void push_down(ll i){
	tree[i<<1].lz+=tree[i].lz;
	tree[i<<1|1].lz+=tree[i].lz;
	tree[i<<1].sum+=tree[i].lz*(tree[i<<1].r-tree[i<<1].l+1);
	tree[i<<1|1].sum+=tree[i].lz*(tree[i<<1|1].r-tree[i<<1|1].l+1);
	tree[i].lz=0;
}

ll search(ll i,ll l,ll r){
	if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;
	push_down(i);
	ll res=0;
	if(tree[i<<1].r>=l) res+=search(i<<1,l,r);
	if(tree[i<<1|1].l<=r) res+=search(i<<1|1,l,r);
	return res;
}

void add(ll i,ll l,ll r,ll k){
	if(tree[i].r<=r&&tree[i].l>=l){
		tree[i].sum+=k*(tree[i].r-tree[i].l+1);
		tree[i].lz+=k;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l) add(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r) add(i<<1|1,l,r,k);
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
	return;
}


int main() {
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    for(int i=1;i<=q;i++){
    	ll x,y,z,k;
    	scanf("%lld",&x);
    	if(x==1) scanf("%lld%lld%lld",&y,&z,&k),add(1,y,z,k);
    	else scanf("%lld%lld",&y,&z),printf("%lld\n",search(1,y,z));
	}
    return 0;
}

