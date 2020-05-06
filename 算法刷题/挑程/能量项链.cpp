#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int n,dp[405][405],a[405];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int len=2;len<=n;len++){
		for(int j=1,ends=len+j-1;ends<2*n&&j<2*n;j++,ends=len+j-1){
			for(int k=j;k<ends;k++){
				dp[j][ends]=max(dp[j][ends],dp[j][k]+dp[k+1][ends]+a[j]*a[k+1]*a[ends+1]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i][i+n-1]);
	cout<<ans<<endl;
	return 0;
}
