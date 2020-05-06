#include<bits/stdc++.h>
using namespace std;
const int mod=1e9;
const int inf=1<<30;
int n,dp[1<<20][25];
int a[25][25];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	memset(dp,67,sizeof(dp));
	dp[1][1]=0;
	for(int i=0;i<1<<n;i++){
		for(int j=1;j<=n;j++){
			if(!((1<<(j-1))&i)){
				for(int k=1;k<=n;k++){
					if((1<<(k-1))&i)
						dp[i|(1<<(j-1))][j]=min(dp[i|(1<<(j-1))][j],dp[i][k]+a[k][j]);
				}
			}
		}
	}
	int ans=inf;
	for(int i=2;i<=n;i++) ans=min(ans,dp[(1<<n)-1][i]+a[i][1]);
	printf("%d\n",ans);
	return 0;
}  //https://www.luogu.com.cn/problem/P1171
