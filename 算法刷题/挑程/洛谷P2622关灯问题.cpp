#include<bits/stdc++.h>
using namespace std;
int dp[1<<15];
int a[105][15];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	memset(dp,0x3f,sizeof(dp));
	dp[(1<<n)-1]=0;
	for(int i=(1<<n)-1;i>=0;i--){
		for(int j=1;j<=m;j++){
			int now=i;
			for(int k=1;k<=n;k++){
				if(a[j][k]==0) continue;
				else if(a[j][k]==1){
					if(i&(1<<n-k)) now=now^(1<<n-k);
				}else if(a[j][k]==-1){
					if(!(i&(1<<n-k))) now=now^(1<<n-k);
				}
			}
			dp[now]=min(dp[now],dp[i]+1);
		}
	}
	printf("%d\n",dp[0]==1061109567?-1:dp[0]);
	return 0;
}
