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
inline ll read() {
	ll kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}

void write(ll x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}

ll n,mm[25][25],cnt;
ll dp[21][1<<17];
ll sta[1<<17];
inline bool ok(int x){
	return !((x&(x<<1))||(x&(x>>1)));
}
inline ll gg(int i,int x){
	ll ans=0;
	for(int j=1;j<=n;j++){
		if((1<<(j-1))&x){
			ans+=1ll*mm[i][n-j+1];
		}
	}
	return ans;
}
int main(){
    while(scanf("%lld",&n)!=EOF){
    	cnt=0;
    	memset(dp,0,sizeof(dp));
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			mm[i][j]=read();
			}
		}
		for(int i=0;i<(1<<n);i++){
			if(ok(i)) sta[cnt++]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<cnt;j++){
				for(int k=0;k<cnt;k++){
					if((sta[k]&sta[j])==0){
						ll sum=gg(i,sta[j]);
						dp[i][j]=max(dp[i][j],dp[i-1][k]+sum);
					}
				}
			}
		}
		ll ans=0;
		for(int i=0;i<cnt;i++){
			ans=max(ans,dp[n][i]);
		}
		write(ans);
		putchar('\n');
	}
    return 0;
}

