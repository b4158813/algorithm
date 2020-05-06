#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,f[100000005];
int dp[10000005];
inline void init(){
	f[0]=1;
	f[1]=1; 
	for(int i=2;i<=n;i++){
		if(f[i]==0)
			dp[++cnt]=i;
		for(int j=1;j<=cnt&&i*dp[j]<=n;j++){
			f[i*dp[j]]=1;
			if(i%dp[j]==0) break;
		}
	}
}
int main(){
	scanf("%d %d",&n,&k);
	init();
	while(k--){
		int x;
		scanf("%d",&x);
		printf("%d\n",dp[x]);
	}
	return 0;
}
