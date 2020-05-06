#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod=19260817; 
inline ll read() { 
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';kk%=mod;cc=getchar();} 
	return kk%mod*f; 
}
ll a,b;
inline ll qpow(ll x,ll y){
	ll base=x,ans=1;
	while(y){
		if(y&1) ans=(ans*base)%mod;
		y>>=1;
		base=(base*base)%mod;
	}
	return ans;
}
int main(){
	a=read(),b=read();
	if(b==0){
		printf("Angry!\n");
		return 0;
	}
	printf("%lld\n",(a*qpow(b,mod-2))%mod);
	return 0;
}
