#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,q,p,op,x,y,k,a[N];
struct Stree{
	ll l,r,plz,mlz,sum;
}tree[N<<2];
inline void build(ll i,ll l,ll r){
	tree[i].l=l,tree[i].r=r,tree[i].mlz=1;
	if(l==r){
		tree[i].sum=a[l]%p;
		return;
	}
	ll mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
	return;
}
inline void push_down(ll i){
	ll k1=tree[i].plz,k2=tree[i].mlz;
	tree[i<<1].sum=(tree[i<<1].sum*k2+k1*(tree[i<<1].r-tree[i<<1].l+1))%p;
	tree[i<<1|1].sum=(tree[i<<1|1].sum*k2+k1*(tree[i<<1|1].r-tree[i<<1|1].l+1))%p;
	tree[i<<1].plz=(tree[i<<1].plz*k2+k1)%p;
	tree[i<<1].mlz=(tree[i<<1].mlz*k2)%p;
	tree[i<<1|1].plz=(tree[i<<1|1].plz*k2+k1)%p;
	tree[i<<1|1].mlz=(tree[i<<1|1].mlz*k2)%p;
	tree[i].plz=0;
	tree[i].mlz=1;
	return;
}
inline void add(ll i,ll l,ll r,ll k){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].sum=(tree[i].sum+k*(tree[i].r-tree[i].l+1))%p;
		tree[i].plz=(tree[i].plz+k)%p;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l) add(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r) add(i<<1|1,l,r,k);
	tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
	return;
}
inline void mul(ll i,ll l,ll r,ll k){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].sum=(tree[i].sum*k)%p;
		tree[i].plz=(tree[i].plz*k)%p;
		tree[i].mlz=(tree[i].mlz*k)%p;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l) mul(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r) mul(i<<1|1,l,r,k);
	tree[i].sum=(tree[i<<1].sum+tree[i<<1|1].sum)%p;
	return;
}

inline ll search(ll i,ll l,ll r){
	if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;
	push_down(i);
	ll res=0;
	if(tree[i<<1].r>=l) res=(res+search(i<<1,l,r))%p;
	if(tree[i<<1|1].l<=r) res=(res+search(i<<1|1,l,r))%p;
	return res%p;
}

int main() {
    scanf("%lld%lld%lld",&n,&q,&p);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    for(int i=1;i<=q;i++){
    	scanf("%lld%lld%lld",&op,&x,&y);
    	if(op==1) scanf("%lld",&k),mul(1,x,y,k);
    	if(op==2) scanf("%lld",&k),add(1,x,y,k);
    	if(op==3) printf("%lld\n",search(1,x,y));
	}
    return 0;
}

