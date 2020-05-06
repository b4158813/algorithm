#include<bits/stdc++.h>
using namespace std;

int dp[10][205];
int n,k;
int main(){
	cin>>n>>k;
	dp[0][0] = 1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(i>j){
				dp[i][j] = 0;
			}else{
				dp[i][j] = dp[i-1][j-1] + dp[i][j-i];
			}
		}
	}
	cout<<dp[k][n]<<endl;
	return 0;
}
