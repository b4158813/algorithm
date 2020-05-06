#include<bits/stdc++.h>
using namespace std;

const int mod=100003;
long long dp[100015];

int main(){
	int n,k;
	cin>>n>>k;
	dp[0]=dp[1]=1;
	for(int i=2;i<=k;i++) dp[i]=(dp[i-1]<<1)%mod;
	for(int i=k+1;i<=n;i++){
		dp[i]=(dp[i-1]*2%mod-dp[i-k-1]%mod+100003)%mod;
	}
	cout<<dp[n]<<endl;
	return 0;
}
