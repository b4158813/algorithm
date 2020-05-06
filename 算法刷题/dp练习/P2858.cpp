#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,a[2005];
int dp[2005][2005];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++) dp[i][i]=a[i]*n;
	for(int len=2;len<=n;len++){
		for(int j=1,ends=j+len-1;ends<=n;j++,ends=j+len-1){
			dp[j][ends]=max(dp[j+1][ends]+a[j]*(n-len+1),dp[j][ends-1]+a[ends]*(n-len+1));
		}
	}
	printf("%d\n",dp[1][n]);
    return 0;
}

