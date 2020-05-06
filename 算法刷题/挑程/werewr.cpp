#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int t[10005],v[10005];
int main(){
	int tot,n;
	cin>>tot>>n;
	for(int i=1;i<=n;i++) cin>>t[i]>>v[i];
	for(int i=1;i<=n;i++){
		for(int j=tot;j>=t[i];j--){
			dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
		}
	}
	cout<<dp[tot]<<endl;
	return 0;
}
