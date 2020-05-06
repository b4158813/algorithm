#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[7][1<<7];
ll a[7][7];
ll cnm[1<<7];
int n,m;
inline bool ok(int x){
	return (!(x&(x<<1))&&(!(x&(x>>1))));
}
inline int getsum(int row,int sta){
	ll sum=0;
	for(int i=1;i<=m;i++){
		if(sta&(1<<i-1)) sum+=a[row][m-i+1];
	}
	return sum;
}
int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		int cnt=0;
		for(int i=0;i<1<<m;i++){
			if(ok(i)) cnm[cnt++]=i;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<cnt;j++){
				ll sum=getsum(i,cnm[j]);
				for(int k=0;k<cnt;k++){
					if((cnm[k]&cnm[j])==0&&((cnm[k]<<1)&cnm[j])==0&&((cnm[k]>>1)&cnm[j])==0){
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
} //https://www.luogu.com.cn/problem/P1123
