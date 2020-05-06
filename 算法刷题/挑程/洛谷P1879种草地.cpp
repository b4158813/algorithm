#include<bits/stdc++.h>
using namespace std;
const int mod=1e9;
int n,m,dp[15][1<<13],a[15][15];
int f[15];
inline bool ok(int x){
	return !(x&(x<<1)||x&(x>>1));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==1) f[i]+=1<<(m-j);
		}
//		printf("%d:%d\n",i,f[i]);
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<m);j++){
			if(ok(j)&&((j&f[i])==j)){
				for(int k=0;k<(1<<m);k++){
					if(ok(k)&&((k&j)==0)){
						dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<1<<m;i++) ans=(ans+dp[n][i])%mod; 
	printf("%d\n",ans);
	
	return 0;
} //https://www.luogu.com.cn/problem/P1879
