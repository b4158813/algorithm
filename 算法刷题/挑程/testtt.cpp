#include <bits/stdc++.h>
using namespace std;
int len,dp[105];
int bound(int x){
	int l=1,r=len;
	while(l<r){
		int mid=(l+r)>>1;
		if(dp[mid]>x) r=mid;
		l=mid+1;
	}
	return l;
}
int main()
{
	int a[105],n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1]=a[1];
	len=1;
	for(int i=2;i<=n;i++){
		if(a[i]>dp[len]) dp[++len]=a[i];
		int pos = bound(a[i]);
		dp[pos]=a[i];
	}
	cout<<len<<endl;
	
//O(n^2)
//	int dp[105];
//	int a[105],n;
//	cin>>n;
//	for(int i=1;i<=n;i++) cin>>a[i];
//	dp[1]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<i;j++){
//			if(a[i]>a[j]) dp[i] = max(dp[i],dp[j]+1);
//		}
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++) ans=max(dp[i],ans);
//	cout<<ans<<endl;
//	return 0;
}
