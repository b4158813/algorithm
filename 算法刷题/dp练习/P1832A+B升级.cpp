#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005; 
int n,f[maxn],prime[maxn],phi[maxn],cnt;
inline void init(int n){
	phi[1]=1;
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++){
		if(f[i]==0){
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			f[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}else phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}
ll dp[maxn];
int main() {
	scanf("%d",&n);
    init(n);
    dp[0]=1;
    for(int i=1;i<=cnt;i++){
    	for(int j=0;j<=n;j++){
    		if(j>=prime[i]) dp[j]+=dp[j-prime[i]];
		}
	}
	printf("%lld\n",dp[n]);
    return 0;
}

