#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
const int N=1e3+5;
int n,m,lose[N],win[N],use[N];
ll dp[N][N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d",&lose[i],&win[i],&use[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j>=use[i]){
				dp[i][j]=max(dp[i-1][j]+1ll*lose[i],dp[i-1][j-use[i]]+1ll*win[i]);
			}else dp[i][j]=dp[i-1][j]+1ll*lose[i];
		}
	}
	printf("%lld\n",dp[n][m]*5);
    return 0;
}

