#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,op,x,y,k,ls[N*40],rs[N*40],tg[N*40],rt,ncnt;
ll sum[N*40];

inline void pushup(int o){
	sum[o]=sum[ls[o]]+sum[rs[o]];
}

inline void init(int &o,int l,int r,int x,int k){
	if(!o) o=++ncnt;
	if(l==r){
		sum[o]+=1ll*k;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x) init(ls[o],l,mid,x,k);
	else init(rs[o],mid+1,r,x,k);
	pushup(o);
}

inline void push_down(int o,int l,int r){
	if(!tg[o]) return;
	if(!ls[o]) ls[o]=++ncnt;
	if(!rs[o]) rs[o]=++ncnt;
	int mid=(l+r)>>1;
	sum[ls[o]]+=tg[o]*(mid-l+1);
	sum[rs[o]]+=tg[o]*(r-mid);
	tg[ls[o]]+=tg[o];
	tg[rs[o]]+=tg[o];
	tg[o]=0;
	return;
}

inline void update(int &o,int l,int r,int L,int R,int k){
	if(!o) o=++ncnt;
	if(l>=L&&r<=R){
		sum[o]+=1ll*k*(r-l+1);
		tg[o]+=k;
		return;
	}
	push_down(o,l,r);
	int mid=(l+r)>>1;
	if(mid>=L) update(ls[o],l,mid,L,R,k);
	if(mid+1<=R) update(rs[o],mid+1,r,L,R,k);
	pushup(o);
}

inline ll getsum(int &o,int l,int r,int L,int R){
	if(!o) return 0;
	if(l>=L&&r<=R) return sum[o];
	push_down(o,l,r);
	ll res=0;
	int mid=(l+r)>>1;
	if(mid>=L) res+=getsum(ls[o],l,mid,L,R);
	if(mid+1<=R) res+=getsum(rs[o],mid+1,r,L,R);
	return res;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%d",&x);
    	init(rt,1,n,i,x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			scanf("%d",&k);
			update(rt,1,n,x,y,k);
		}else{
			printf("%lld\n",getsum(rt,1,n,x,y));
		}
	}
    return 0;
}

