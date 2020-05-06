#include<bits/stdc++.h>
using namespace std;
int n,a[205][205]; 
int dp[205];
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
    	for(int j=i+1;j<=n;j++){
    		scanf("%d",&a[i][j]);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[2]=a[1][2];
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			dp[j]=min(dp[j],dp[i]+a[i][j]);
		}
	}
	printf("%d\n",dp[n]);
    return 0;
}

