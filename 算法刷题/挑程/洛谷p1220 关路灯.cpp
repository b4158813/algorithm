#include<bits/stdc++.h>
using namespace std;
int pos[1005],power[1005];
int n,st;
int dp[55][55][3];
inline int cal(int i,int j,int l,int r){
	return (pos[r]-pos[l])*(power[i]+power[n]-power[j]);
}
int main(){
	cin>>n>>st;
	for(int i=1;i<=n;i++) cin>>pos[i]>>power[i];
	for(int i=1;i<=n;i++) power[i]=power[i-1]+power[i];
	memset(dp,0x3f3f3f,sizeof(dp));
	dp[st][st][0]=dp[st][st][1]=0;
	
	for(int j=st;j<=n;j++){
		for(int i=j-1;i>=1;i--){
			dp[i][j][0]=min(dp[i+1][j][0]+cal(i,j,i,i+1),dp[i+1][j][1]+cal(i,j,i,j));
			dp[i][j][1]=min(dp[i][j-1][0]+cal(i-1,j-1,i,j),dp[i][j-1][1]+cal(i-1,j-1,j-1,j));
		}
	}
	cout<<min(dp[1][n][1],dp[1][n][0])<<endl;
	return 0;
}
