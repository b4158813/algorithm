#include<bits/stdc++.h>
using namespace std;
int n,dp[1005];
int main(){
	dp[1]=1;
	cin>>n;
	for(int i=2;i<=n;i++){
		if(i&1) dp[i]=dp[i-1];
		else dp[i]=dp[i-1]+dp[i/2];
	}
	cout<<dp[n]<<endl;
	return 0;
}
