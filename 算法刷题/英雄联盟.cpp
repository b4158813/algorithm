#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[8000005],n,m;
ll a[10005],b[10005];
ll tot;
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		tot+=b[i]*a[i];
	} 
	dp[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=tot;j>=0;--j){
			for(ll k=1;k<=a[i];k++){
				if(j>=k*b[i]){
					dp[j]=max(dp[j],dp[j-k*b[i]]*k);
				}
			}
		}
	}
	for(ll i=0;i<=tot;i++){
		if(dp[i]>=m){
			printf("%lld\n",i);
			return 0;
		}
	}
}
