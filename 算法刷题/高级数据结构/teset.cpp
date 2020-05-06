#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n,q,a[N];
struct Stree{
	int l,r,lz;
	ll sum;
}tree[N<<2];
void build(int i,int l,int r){
	tree[i].l=l,tree[i].r=r;
	if(l==r){
		tree[i].sum=1ll*a[l];
		return;
	}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
	return;
}
void push_down(int i){
	if(tree[i].lz!=0){
		tree[i<<1].lz+=tree[i].lz;
		tree[i<<1|1].lz+=tree[i].lz;
		tree[i<<1].sum+=1ll*(tree[i<<1].r-tree[i<<1].l+1)*tree[i].lz;
		tree[i<<1|1].sum+=1ll*(tree[i<<1|1].r-tree[i<<1|1].l+1)*tree[i].lz;
		tree[i].lz=0;
	}
	return;
}

void add(int i,int l,int r,int k){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].sum+=1ll*(tree[i].r-tree[i].l+1)*k;
		tree[i].lz+=k;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l) add(i<<1,l,r,k);
	if(tree[i<<1|1].l<=r) add(i<<1|1,l,r,k);
	tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
	return;
}

ll getsum(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;
	push_down(i);
	ll res=0;
	if(tree[i<<1].r>=l) res+=getsum(i<<1,l,r);
	if(tree[i<<1|1].l<=r) res+=getsum(i<<1|1,l,r);
	return res;
}

int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    int op,x,y,z;
    for(int i=1;i<=q;i++){
    	scanf("%d%d%d",&op,&x,&y);
    	if(op==1) scanf("%d",&z),add(1,x,y,z);
    	else printf("%lld\n",getsum(1,x,y));
	}
    return 0;
}

