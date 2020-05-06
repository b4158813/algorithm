#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int dp1[805][805],dp2[805][805];
int a[4005],sum[4005];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		dp2[i][i]=0;
	}
	for(int i=1;i<=n;i++) sum[i+n]=sum[i+n-1]+a[i];
	
	for(int len=1;len<=n;len++){
		for(int j=1,lens=j+len;lens<2*n&&j<2*n;j++,lens=j+len){
			dp2[j][lens]=inf;
			for(int k=j;k<lens;k++){
				dp2[j][lens]=min(dp2[j][lens],dp2[j][k]+dp2[k+1][lens]+sum[lens]-sum[j-1]);
				dp1[j][lens]=max(dp1[j][lens],dp1[j][k]+dp1[k+1][lens]+sum[lens]-sum[j-1]);
			}
		}
	}
	int ansmin=inf,ansmax=0;
	for(int i=1;i<=n;i++){
		ansmin=min(ansmin,dp2[i][i+n-1]);
		ansmax=max(ansmax,dp1[i][i+n-1]);
	}
	
	cout<<ansmin<<endl<<ansmax<<endl;
	return 0;
}
