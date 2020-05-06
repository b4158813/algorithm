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
const int maxn=10000;
const int mod=1e9+7;
int n,m,mm[55][55];
int dp[250][55][55];


int main() {
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++){
    		scanf("%d",&mm[i][j]);
		}
	for(int sum=2;sum<=n+m-1;sum++){
		for(int i=1;i<=n&&i<=sum;i++){
			for(int j=1;j<=n&&j<=sum;j++){
				dp[sum][i][j]=max(max(dp[sum-1][i-1][j],dp[sum-1][i][j-1]),max(dp[sum-1][i][j],dp[sum-1][i-1][j-1]));
				dp[sum][i][j]+=(i==j)?mm[i][sum-i+1]:(mm[i][sum-i+1]+mm[j][sum-j+1]);
			}
		}
	}
	printf("%d\n",dp[n+m-1][n][n]);
    return 0;
}

