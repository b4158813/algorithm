#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
struct M{
	ll mat[15][15];
}a;
M operator*(M x1,M x2){
	M res;
	memset(res.mat,0,sizeof(res));
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				res.mat[i][j]+=(x1.mat[i][k]%mod*x2.mat[k][j]%mod)%mod;
				res.mat[i][j]%=mod;
			}
		}
	}
	return res;
}

inline M qpow(M a,ll y,M ans){
	M base=a;
	while(y>0){
		if(y&1) ans=ans*base;
		y>>=1;
		base=base*base;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll nn;
		cin>>nn;
		memset(a.mat,0,sizeof(a));
		M b;
		memset(b.mat,0,sizeof(b));
		b.mat[1][1]=b.mat[1][2]=b.mat[1][3]=1;
		a.mat[1][1]=a.mat[1][2]=a.mat[2][2]=a.mat[2][3]=a.mat[3][1]=0;
		a.mat[1][3]=a.mat[2][1]=a.mat[3][2]=a.mat[3][3]=1;
		M ans=qpow(a,nn-1,b);
		cout<<ans.mat[1][1]<<endl;
	}
	return 0;
}
