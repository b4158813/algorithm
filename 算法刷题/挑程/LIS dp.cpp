#include<bits/stdc++.h>
using namespace std;

int dp[100005],a[100005];
int len,n;
int ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j]<a[i])
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	for(int i=1;i<=n;i++){
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
