#include<bits/stdc++.h>
using namespace std;
int dp[305][305];
const int inf = 1<<30;
int n,m,t;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j],max(dp[i][k],dp[k][j]));
			}
		}
	}
}

void clean(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]==0) dp[i][j]=inf;
		}
	}
}
int main(){
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		dp[x][y]=z;
	}
	clean();
	floyd();
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		if(dp[x][y]==inf) cout<<"-1"<<endl;
		else cout<<dp[x][y]<<endl;
	}
	return 0;
}
