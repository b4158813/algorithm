#include<bits/stdc++.h>
using namespace std;
int dp1[105],dp2[105],a[105];
int ans;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]) dp1[i] = max(dp1[i],dp1[j]+1);
		}
	}
	for(int i=n;i>=1;i--){
		dp[i]=1;
		for(int j=n;j>=1;j--){
			if(a[i]>a[j]) dp2[i] = max(dp2[i],dp2[j]+1);
		}
	}
	for(int i=1;i<=n;i++){
		ans = max(ans,dp1[i]+dp2[i]-1);
	}
	cout<<n-ans<<endl;
	return 0;
}
