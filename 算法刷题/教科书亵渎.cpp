#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
struct M{
	ll mat[7][7];
};
ll a1,a2,a3,n;
M operator*(M x1,M x2){
	M res;
	memset(res.mat,0,sizeof(res.mat));
	for(int k=1;k<=4;k++){
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				res.mat[i][j]+=(x1.mat[i][k]%mod*x2.mat[k][j]%mod)%mod;
				res.mat[i][j]%=mod;
			}
		}
	}
	return res;
}


inline M mqpow(M ans,ll y,M a){
	while(y>0){
		if(y&1) ans=ans*a;
		y>>=1;
		a=a*a;
	}
	return ans;
}

int main(){
	scanf("%lld%lld%lld%lld",&a1,&a2,&a3,&n);
	if(a1==0){
		printf("0\n");
		return 0;
	}
	if(a2==0){
		printf("%lld\n",a1%mod);
		return 0;
	}
	if(a3==0){
		printf("%lld\n",(a1+a2)%mod);
		return 0;
	}
	M a,b;
	memset(a.mat,0,sizeof(a.mat));
	memset(b.mat,0,sizeof(b.mat));
	a.mat[1][1]=a1;
	a.mat[1][2]=a2;
	a.mat[1][3]=a3;
	a.mat[1][4]=0;
	b.mat[2][1]=b.mat[2][3]=b.mat[1][4]=b.mat[3][2]=b.mat[3][3]=b.mat[4][4]=1;
	M ans=mqpow(a,n,b);
	printf("%lld\n",ans.mat[1][4]);
	return 0;
}
