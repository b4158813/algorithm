#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll x,y,a,b,c;
void exgcd(ll a,ll b){
	if(b==0){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b);
	ll tx=x,ty=y;
	x=ty;
	y=tx-a/b*ty;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		x=0,y=0;
		scanf("%lld%lld%lld",&a,&b,&c);
		ll g=gcd(a,b);
		if(c%g!=0){
			printf("-1\n");
			continue;
		}else{
		a/=g,b/=g,c/=g;
		exgcd(a,b);
		x*=c,y*=c;
		ll minx=(x%b+b)%b;
		if(!minx) minx+=b;
		ll miny=(y%a+a)%a;
		if(!miny) miny+=a;
		ll maxy=(c-(a*minx))/b;
		ll maxx=(c-(b*miny))/a;
		ll cnt=(maxx-minx)/b+1;
		if(cnt) printf("%lld %lld %lld %lld %lld\n",cnt,minx,miny,maxx,maxy);
		else printf("%lld %lld\n",minx,miny);
		}
	}
	return 0;
}
