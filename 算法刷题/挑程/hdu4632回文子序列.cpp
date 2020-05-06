#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
int dp[2005][2005];
int main(){
	int t;
	cin>>t;
	for(int m=1;m<=t;m++){
		memset(dp,0,sizeof(dp));
		string s;
		cin>>s;
		int lens=s.length();
		for(int i=0;i<lens;i++) dp[i][i]=1;
		for(int i=2;i<=lens;i++){
			for(int j=0,ends=j+i-1;ends<lens;j++,ends=j+i-1){
				dp[j][ends]=((dp[j+1][ends]+dp[j][ends-1]-dp[j+1][ends-1])%mod+mod)%mod;
				if(s[j]==s[ends])
					dp[j][ends]=(dp[j][ends]+dp[j+1][ends-1]+1)%mod;
			}
		}
		printf("Case %d: %d\n",m,dp[0][lens-1]%mod);
	}
	return 0;
}// https://vjudge.net/problem/HDU-4632
