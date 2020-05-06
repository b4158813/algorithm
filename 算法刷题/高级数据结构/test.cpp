#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m,p,a[N];
struct Stree{
	ll l,r,plz,mlz,sum;
}tr[N<<2];
inline void build(ll i,ll l,ll r){
	tr[i].l=l,tr[i].r=r,tr[i].mlz=1;
	if(l==r){
		tr[i].sum=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tr[i].sum=(tr[i<<1].sum+tr[i<<1|1].sum)%p;
	return;
}
inline void push_down(ll i){
	ll k1=tr[i].plz,k2=tr[i].mlz;
	tr[i<<1].sum=(tr[i<<1].sum*k2+k1*(tr[i<<1].r-tr[i<<1].l+1))%p;
	tr[i<<1|1].sum=(tr[i<<1|1].sum*k2+k1*(tr[i<<1|1].r-tr[i<<1|1].l+1))%p;
	tr[i<<1].plz=(tr[i<<1].plz*k2+k1)%p;
	tr[i<<1|1].plz=(tr[i<<1|1].plz*k2+k1)%p;
	tr[i<<1].mlz=(tr[i<<1].mlz*k2)%p;
	tr[i<<1|1].mlz=(tr[i<<1|1].mlz*k2)%p;
	tr[i].plz=0;
	tr[i].mlz=1;
	return;
}
inline void add(ll i,ll l,ll r,ll k){
	if(tr[i].l>=l&&tr[i].r<=r){
		tr[i].sum=(tr[i].sum+k*(tr[i].r-tr[i].l+1))%p;
		tr[i].plz=(tr[i].plz+k)%p;
		return;
	}
	push_down(i);
	if(tr[i<<1].r>=l) add(i<<1,l,r,k);
	if(tr[i<<1|1].l<=r) add(i<<1|1,l,r,k);
	tr[i].sum=(tr[i<<1].sum+tr[i<<1|1].sum)%p;
	return;
}
inline void mul(ll i,ll l,ll r,ll k){
	if(tr[i].l>=l&&tr[i].r<=r){
		tr[i].sum=(tr[i].sum*k)%p;
		tr[i].plz=(tr[i].plz*k)%p;
		tr[i].mlz=(tr[i].mlz*k)%p;
		return;
	}
	push_down(i);
	if(tr[i<<1].r>=l) mul(i<<1,l,r,k);
	if(tr[i<<1|1].l<=r) mul(i<<1|1,l,r,k);
	tr[i].sum=(tr[i<<1].sum+tr[i<<1|1].sum)%p;
	return;
}
inline ll getsum(ll i,ll l,ll r){
	if(tr[i].l>=l&&tr[i].r<=r) return tr[i].sum%p;
	push_down(i);
	ll res=0;
	if(tr[i<<1].r>=l) res=(res+getsum(i<<1,l,r))%p;
	if(tr[i<<1|1].l<=r) res=(res+getsum(i<<1|1,l,r))%p;
	return res%p;
}
int main() {
    scanf("%lld%lld%lld",&n,&m,&p);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
    	ll op,x,y,k;
    	scanf("%lld",&op);
    	if(op==2){
    		scanf("%lld%lld%lld",&x,&y,&k),add(1,x,y,k);
		}
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k),mul(1,x,y,k);
		}
		if(op==3){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",getsum(1,x,y));
		}
	}
    return 0;
}

