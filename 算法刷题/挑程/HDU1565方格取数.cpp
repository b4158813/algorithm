#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[21][1<<17];
ll a[21][21];
ll cnm[1<<17];
int n;
inline bool ok(int x){
	return (!(x&(x<<1))&&(!(x&(x>>1))));
}
inline int getsum(int row,int sta){
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(sta&(1<<i-1)) sum+=a[row][n-i+1];
	}
	return sum;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		int cnt=0;
		for(int i=0;i<1<<n;i++){
			if(ok(i)) cnm[cnt++]=i;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<cnt;j++){
				ll sum=getsum(i,cnm[j]);
				for(int k=0;k<cnt;k++){
					if((cnm[j]&cnm[k])==0){
						dp[i][j]=max(dp[i][j],dp[i-1][k]+sum);
					}
				}
			}
		}
		ll ans=0;
		for(int i=0;i<cnt;i++){
			ans=max(ans,dp[n][i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
} //https://vjudge.net/problem/HDU-1565
