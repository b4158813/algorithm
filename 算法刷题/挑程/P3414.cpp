#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll mod=6662333;

ll kpow(ll x,ll y){
	ll ans=1,base=x;
	while(y>0){
		if(y&1){
			ans*=base;
			ans%=mod;
		}
		base*=base;
		base%=mod;
		y=y>>1;
	}
	return ans;
}

int main(){
	cin>>n;
	cout<<kpow(2,n-1)<<endl;
	return 0;
}
