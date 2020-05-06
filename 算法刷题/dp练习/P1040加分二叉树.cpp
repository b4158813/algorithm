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
int n,a[55],rt[55][55];
ll dp[55][55];
void print(int l,int r){
	if(l>r) return;
	printf("%d ",rt[l][r]);
	if(l==r) return;
	print(l,rt[l][r]-1);
	print(rt[l][r]+1,r);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),dp[i][i]=1ll*a[i],dp[i][i-1]=1,rt[i][i]=i;
    for(int len=2;len<=n;len++){
    	for(int i=1,j=i+len-1;j<=n;i++,j=i+len-1){
    		dp[i][j]=dp[i+1][j]+dp[i][i];
    		rt[i][j]=i;
    		for(int k=i+1;k<j;k++){
    			if(dp[i][j]<dp[i][k-1]*dp[k+1][j]+dp[k][k]){
    				dp[i][j]=dp[i][k-1]*dp[k+1][j]+dp[k][k];
    				rt[i][j]=k;
				}
			}
		}
	}
	printf("%lld\n",dp[1][n]);
	print(1,n);
	return 0;
}

