#include<bits/stdc++.h>
using namespace std;
int dp[10005],a[10005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i]&1){
				if(a[i]<a[j]) dp[j] = max(dp[j],dp[i]+1);
			}else{
				if(a[i]>a[j]) dp[j] = max(dp[j],dp[i]+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
