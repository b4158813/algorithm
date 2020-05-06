#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
void write(ll x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}

const int N=1e5+5;
ll n,m,a[N];
struct Stree{
	ll l,r,mx,sum;
}tr[N<<2];
inline void build(ll i,ll l,ll r){
	tr[i].l=l,tr[i].r=r;
	if(l==r){
		tr[i].sum=tr[i].mx=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum;
	tr[i].mx=max(tr[i<<1].mx,tr[i<<1|1].mx);
	return;
}
inline void modify(ll i,ll k,ll x){
	if(tr[i].l==tr[i].r){
		tr[i].sum=tr[i].mx=x;
		return;
	}
	if(tr[i<<1].r>=k) modify(i<<1,k,x);
	else modify(i<<1|1,k,x);
	tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum;
	tr[i].mx=max(tr[i<<1].mx,tr[i<<1|1].mx);
}
inline void Mod(ll i,ll l,ll r,ll x){
	if(tr[i].mx<x) return;
	if(tr[i].l==tr[i].r){
		tr[i].sum%=x;
		tr[i].mx%=x;
		return;
	}
	if(tr[i<<1].r>=l) Mod(i<<1,l,r,x);
	if(tr[i<<1|1].l<=r) Mod(i<<1|1,l,r,x);
	tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum;
	tr[i].mx=max(tr[i<<1].mx,tr[i<<1|1].mx);
	return;
}
inline ll getsum(ll i,ll l,ll r){
	if(tr[i].l>=l&&tr[i].r<=r) return tr[i].sum;
	ll res=0;
	if(tr[i<<1].r>=l) res+=getsum(i<<1,l,r);
	if(tr[i<<1|1].l<=r) res+=getsum(i<<1|1,l,r);
	return res;
}
int main() {
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);
    for(int i=1;i<=m;i++){
    	ll op,l,r,x,k;
    	op=read();
    	if(op==1){
    		l=read(),r=read();
    		write(getsum(1,l,r));
    		putchar('\n');
		}
		if(op==2){
			l=read(),r=read(),x=read();
			Mod(1,l,r,x);
		}
		if(op==3){
			k=read(),x=read();
			modify(1,k,x);
		}
	}
    return 0;
}

