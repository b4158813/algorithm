#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e9;
ll mm[115][115],n,m;
ll dp[115][115],ans;

inline void floyd(){
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<k;i++){
			for(ll j=i+1;j<k;j++){
				if(ans>dp[i][j]+mm[i][k]+mm[k][j])
					ans=dp[i][j]+mm[i][k]+mm[k][j];
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
				}
				dp[j][i]=dp[i][j];
			}
		}
	}
}
int main(){
	scanf("%lld%lld",&n,&m);
	ll u,v,w;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i!=j) dp[i][j]=mm[i][j]=inf;
		}
	} 
	for(ll i=1;i<=m;++i){
		scanf("%lld%lld%lld",&u,&v,&w);
		dp[u][v]=dp[v][u]=mm[u][v]=mm[v][u]=min(w,dp[u][v]);
	}
	ans=inf;
	floyd();
	if(ans==inf) printf("No solution.\n");
	else printf("%lld\n",ans);
	return 0;
}
