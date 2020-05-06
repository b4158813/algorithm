#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b,p,k;
ll ans;

ll qpow(ll b,ll p){
	ll ans=1;
	ll base=b;
	while(p>0){
		if(p&1) {
			ans*=base;
			ans%=k;
		}
		base*=base;
		base%=k;
		p>>=1;
	}
	return ans%k;
}

int main(){
	cin>>b>>p>>k;
	ans=qpow(b,p);
	printf("%lld^%lld mod %lld=%lld\n",b,p,k,ans);
	return 0;
}
