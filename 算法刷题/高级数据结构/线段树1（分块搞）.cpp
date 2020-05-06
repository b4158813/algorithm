#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m,a[N];
ll sum[N],st[N],en[N],bel[N],tg[N],sz[N];

inline void init_blk(){
	ll blk=sqrt(n);
	ll num=n/blk;
    for(int i=1;i<=blk;i++){
    	st[i]=num*(i-1)+1;
    	en[i]=num*i;
	}
	en[blk]=n;
	for(int i=1;i<=blk;i++){
		for(int j=st[i];j<=en[i];j++){
			bel[j]=i;
			sum[i]+=a[j];
		}
	}
	for(int i=1;i<=blk;i++){
		sz[i]=en[i]-st[i]+1;
	}
}

inline void add(ll l,ll r,ll k){
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++){
			a[i]+=k;
			sum[bel[i]]+=k;
		}
	}else{
		for(ll i=l;i<=en[bel[l]];i++){
			a[i]+=k;
			sum[bel[i]]+=k;
		}
		for(ll i=st[bel[r]];i<=r;i++){
			a[i]+=k;
			sum[bel[i]]+=k;
		}
		for(ll i=bel[l]+1;i<=bel[r]-1;i++){
			tg[i]+=k;
		}
	}
}

inline ll getsum(ll l,ll r){
	ll ans=0;
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++){
			ans+=a[i]+tg[bel[i]];
		}
	}else{
		for(ll i=l;i<=en[bel[l]];i++){
			ans+=a[i]+tg[bel[i]];
		}
		for(ll i=st[bel[r]];i<=r;i++){
			ans+=a[i]+tg[bel[i]];
		}
		for(ll i=bel[l]+1;i<=bel[r]-1;i++){
			ans+=sz[i]*tg[i]+sum[i];
		}
	}
	return ans;
}

int main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    init_blk();
	for(int i=1;i<=m;i++){
		ll op,x,y,k;
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			add(x,y,k);
		}else{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",getsum(x,y));
		}
	}
    return 0;
}

