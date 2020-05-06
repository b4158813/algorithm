#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005];
int dp[10005][10005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
		for(int j=1;j<=m;j++){
			int minx = min(j,a[i]);
			for(int k=0;k<=minx;k++) dp[i][j]+=dp[i-1][j-k];
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
