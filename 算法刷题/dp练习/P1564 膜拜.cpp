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
int n,m,a[2505],sum[2505];
int dp[2505];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	int x;
    	scanf("%d",&x);
    	if(x==2) a[i]=a[i-1]-1;
    	else a[i]=a[i-1]+1;
    	dp[i]=1e9;
	}
	dp[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(a[i]-a[j-1])==i-j+1||abs(a[i]-a[j-1])<=m){
				dp[i]=min(dp[i],dp[j-1]+1);
			}
		}
	}
	printf("%d\n",dp[n]);
    return 0;
}

