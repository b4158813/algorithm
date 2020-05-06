#include<cstdio> 
#include<cstring>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long ll;
int n;
ll a[500005],c[500005];
inline ll lowbit(ll x){return x&-x;}
inline void update(int i,ll k){
	while(i<=n) c[i]+=k,i+=lowbit(i);
} 
inline ll getsum(int i){
	ll res=0;
	while(i>0) res+=c[i],i-=lowbit(i);
	return res;
}

int main(){
	while(~scanf("%d",&n)){
		memset(c,0,sizeof(c));
		if(n==0) break;
		ll ans=0;
		vector<ll> vec;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),vec.push_back(a[i]);
		sort(vec.begin(),vec.end());
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		for(int i=1;i<=n;i++){
			int pos=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
			update(pos+1,1);
			ans+=i-getsum(pos+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
