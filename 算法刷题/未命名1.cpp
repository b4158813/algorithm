#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e7+7;
inline ll read() { 
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}

ll n,m,a[15];
struct M{
	ll mat[20][20];
};

M operator*(M x1,M x2){
	M res;
	memset(res.mat,0,sizeof(res.mat));
	for(int i=1;i<=n+2;i++){
		for(int j=1;j<=n+2;j++){
			for(int k=1;k<=n+2;k++){
				res.mat[i][j]+=(x1.mat[i][k]%mod*x2.mat[k][j]%mod)%mod;
				res.mat[i][j]%=mod; 
			}
		}
	}
	return res;
}

inline M mqpow(M a,ll y,M giao){
	while(y>0){
		if(y&1) a=a*giao;
		giao=giao*giao;
		y>>=1;
	}
	return a;
}

int main(){
	while(scanf("%lld%lld",&n,&m)!=EOF){
		memset(a,0,sizeof(a));
		for(ll i=1;i<=n;i++) a[i]=read();
		M ori,b;
		memset(b.mat,0,sizeof(b.mat));
		memset(ori.mat,0,sizeof(ori.mat));
		for(int i=1;i<=n+1;i++) 
			b.mat[1][i]=10,b.mat[n+2][i]=1;
		b.mat[n+2][n+2]=1;
		for(int i=2;i<=n+1;i++){
			for(int j=i;j<=n+1;j++){
				b.mat[i][j]=1;
			}
		}
		ori.mat[1][1]=23;
		ori.mat[1][n+2]=3;
		for(int i=2;i<=n+1;i++){
			ori.mat[1][i]=a[i-1];
		}
		M ans=mqpow(ori,m,b);
		printf("%lld\n",ans.mat[1][n+1]%mod);
	}
	return 0;
}
