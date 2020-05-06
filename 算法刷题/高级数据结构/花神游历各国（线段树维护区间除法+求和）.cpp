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
	ll l,r,mx,mn,lz,sum;
}tr[N<<2];
inline void build(ll i,ll l,ll r){
	tr[i].l=l,tr[i].r=r,tr[i].lz=0;
	if(l==r){
		tr[i].sum=tr[i].mx=tr[i].mn=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum;
	tr[i].mx=max(tr[i<<1].mx,tr[i<<1|1].mx);
	tr[i].mn=min(tr[i<<1].mn,tr[i<<1|1].mn);
	return;
}
inline void push_down(ll i){
	if(tr[i].lz==0) return;
	tr[i<<1].mx+=tr[i].lz;
	tr[i<<1|1].mx+=tr[i].lz;
	tr[i<<1].mn+=tr[i].lz;
	tr[i<<1|1].mn+=tr[i].lz;
	tr[i<<1].sum+=tr[i].lz*(tr[i<<1].r-tr[i<<1].l+1);
	tr[i<<1|1].sum+=tr[i].lz*(tr[i<<1|1].r-tr[i<<1|1].l+1);
	tr[i<<1].lz+=tr[i].lz;
	tr[i<<1|1].lz+=tr[i].lz;
	tr[i].lz=0;
	return;
}
inline void Sqrt(ll i,ll l,ll r){
	if(tr[i].l==tr[i].r){
		tr[i].sum=tr[i].mx=tr[i].mn=floor(sqrt(tr[i].sum));
		return;
	}
	push_down(i);
	if(tr[i<<1].r>=l&&tr[i<<1].mx>1) Sqrt(i<<1,l,r);
	if(tr[i<<1|1].l<=r&&tr[i<<1|1].mx) Sqrt(i<<1|1,l,r);
	tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum;
	tr[i].mx=max(tr[i<<1].mx,tr[i<<1|1].mx);
	tr[i].mn=min(tr[i<<1].mn,tr[i<<1|1].mn);
	return;
}
inline ll getsum(ll i,ll l,ll r){
	if(tr[i].l>=l&&tr[i].r<=r) return tr[i].sum;
	push_down(i);
	ll res=0;
	if(tr[i<<1].r>=l) res+=getsum(i<<1,l,r);
	if(tr[i<<1|1].l<=r) res+=getsum(i<<1|1,l,r);
	return res;
}
int main() {
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);
    m=read();
    for(int i=1;i<=m;i++){
    	ll op,x,y;
    	op=read(),x=read(),y=read();
    	if(x>y) swap(x,y);
    	if(op==0) Sqrt(1,x,y);
		else write(getsum(1,x,y)),putchar('\n');
	}
    return 0;
}

