#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll t,n,tot,l,r,vis[N],b[N];
struct node{
	ll l,r;
}a[N];
struct Stree{
	ll l,r,col;
}tree[N<<2];
inline void init(){
	memset(b,0,sizeof(b));
	memset(vis,0,sizeof(vis));
	ll temp=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].l,&a[i].r);
		b[++temp]=a[i].l,b[++temp]=a[i].r;
	}
	sort(b+1,b+1+temp);
	tot=unique(b+1,b+1+temp)-b-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(b+1,b+1+tot,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+1+tot,a[i].r)-b;
	}
}
inline void build(ll i,ll l,ll r){
	tree[i].l=l,tree[i].r=r,tree[i].col=0;
	if(l==r){
		return;
	}
	ll mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	return;
}
inline void push_down(ll i){
	if(tree[i].col==0) return;
	tree[i<<1].col=tree[i<<1|1].col=tree[i].col;
	tree[i].col=0;
	return;
}
inline void update(ll i,ll l,ll r,ll col){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].col=col;
		return;
	}
	push_down(i);
	if(tree[i<<1].r>=l) update(i<<1,l,r,col);
	if(tree[i<<1|1].l<=r) update(i<<1|1,l,r,col);
}
inline void search(ll i,ll l,ll r,ll &ans){
	if(tree[i].col){
		if(!vis[tree[i].col]){
			vis[tree[i].col]=1;
			ans++;
		}
		return;
	}
	search(i<<1,l,r,ans);
	search(i<<1|1,l,r,ans);
	return;
}
inline ll ask(ll l,ll r){
	ll ans=0;
	search(1,l,r,ans);
	return ans;
}

int main() {
    scanf("%lld",&t);
    while(t--){
    	init();
	    build(1,1,tot);
	    ll col=0;
	    for(int i=1;i<=n;i++){
	    	update(1,a[i].l,a[i].r,++col);
		}
		printf("%lld\n",ask(1,tot));
	}
    return 0;
}

