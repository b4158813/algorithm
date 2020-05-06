#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int t,n,m,p[105][105];
int dp[10005];
int main() {
    scanf("%d%d%d",&t,&n,&m);
    for(int i=1;i<=t;i++){
    	for(int j=1;j<=n;j++){
    		scanf("%d",&p[i][j]);
		}
	}
	for(int i=1;i<t;i++){
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++){
			for(int k=p[i][j];k<=m;k++){
				dp[k]=max(dp[k],dp[k-p[i][j]]+p[i+1][j]-p[i][j]);
			}
		}
		m=max(m,dp[m]+m);
	}
	printf("%d\n",m);
    return 0;
}

