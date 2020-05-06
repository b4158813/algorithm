#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10000005];
ll a[1000005],b;
ll num[101]={0,1,2,3,5,10,20};
ll cnt=0,ans=0;
ll maxx=0;
int main(){
	for(int i=1;i<=6;i++){
		cin>>b;
		for(int j=1;j<=b;j++){
			a[++cnt] = num[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		maxx+=a[i];
	}
	dp[0]=1;
	for(int i=1;i<=cnt;i++){
		for(int j=maxx;j>=a[i];j--){
			dp[j] = dp[j] + dp[j-a[i]];
		}
	}
	for(int i=1;i<=maxx;i++){
		if(dp[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
