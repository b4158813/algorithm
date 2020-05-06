#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn=10000;
const int mod=1e9+7;
ll n,p;
ll yin[5000005],ge[50000005],cnt;
inline void init(){
	for(ll i=2;i*i<=p;i++){
		if(p%i==0){
			yin[++cnt]=i;
		}
		while(p%i==0){
			ge[cnt]++;
			p/=i;
		}
	}
	if(p!=1) yin[++cnt]=p,ge[cnt]++;
}

int main() {
    scanf("%lld%lld",&n,&p);
    init();
//    for(int i=1;i<=cnt;i++){
//    	printf("yin%lld:%lld ci:%lld\n",i,yin[i],ge[i]);
//	}
    ll ans=1;
    for(ll i=1;i<=cnt;i++){
    	if(ge[i]>=n){
    		for(ll j=1;j<=ge[i]/n;j++)
				ans*=yin[i];
		}
	}
	printf("%lld\n",ans);
    return 0;
}

