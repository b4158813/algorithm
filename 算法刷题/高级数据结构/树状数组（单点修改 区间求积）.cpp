#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n,m;
ll x,y,z;
ll c[1000005];
inline ll lowbit(ll x){
	return x&-x;
}
inline ll qpow(ll x,ll y){
    ll base=x,ans=1;
    while(y>0){
        if(y&1) ans=(ans*base)%mod;
        y>>=1;
        base=(base*base)%mod;
    }
    return ans%mod;
}
inline void update(ll i,ll k){
    while(i<=n) c[i]=(c[i]*k)%mod,i+=lowbit(i);
}
inline ll getsum(ll i){
    ll res=1;
    while(i>0) res=(res*c[i])%mod,i-=lowbit(i);
    return res%mod;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) c[i]=1;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        if(x==1) update(y,z);
        else if(x==2) update(y,qpow(z,mod-2));
        else printf("%lld\n",getsum(z)*qpow(getsum(y-1),mod-2)%mod);
    }
    return 0;
}
