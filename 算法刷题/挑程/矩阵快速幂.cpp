#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
struct M{
	ll mat[105][105];
}a;
ll n,k;
M operator*(M x1,M x2){
	M res;
	memset(res.mat,0,sizeof(res.mat));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				res.mat[i][j]+=(x1.mat[i][k]*x2.mat[k][j])%mod;
				res.mat[i][j]%=mod; 
			}
		}
	}
	return res;
}

inline M qpow(M x,ll y){
	M base=x,ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) ans.mat[i][j]=1;
			else ans.mat[i][j]=0;
		}
	}
	while(y>0){
		if(y&1) ans=ans*base;
		base=base*base;
		y>>=1;
	}
	return ans;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a.mat[i][j];
		}
	}
	M ans=qpow(a,k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans.mat[i][j]%mod<<" ";
		}
		cout<<endl;
	}
	return 0;
}


