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
const int mod=1e9;
int n,m,mm[15][15];
int sta[15];
int dp[15][1<<13];
inline bool ok(int x){
	return !((x&(x<<1))||(x&(x>>1)));
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		scanf("%d",&mm[i][j]);
    		if(mm[i][j]==1) sta[i]+=1<<(m-j);
		}
	}
	dp[0][0]=1; 
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<m);j++){
			if(ok(j)&&((j&sta[i])==j)){
				for(int k=0;k<(1<<m);k++){
					if(ok(k)&&((k&sta[i-1])==k)&&(k&j)==0){
						dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<m);i++){
		ans=(ans+dp[n][i])%mod;
	}
	printf("%d\n",ans%mod);
    return 0;
}

