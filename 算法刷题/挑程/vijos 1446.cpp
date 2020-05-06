#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dp[i][j]=0;
			else dp[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		dp[x][y]=dp[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	int p;
	cin>>p;
	for(int i=1;i<=p;i++){
		int x,y;
		cin>>x>>y;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(dp[x][y]==dp[x][i]+dp[i][y])
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
