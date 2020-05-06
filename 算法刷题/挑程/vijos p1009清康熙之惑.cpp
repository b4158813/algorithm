#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll x,y,m,n,l;
ll xx,yy;
ll exgcd(ll a,ll b){
	if(b==0){
		xx=1,yy=0;
		return a;
	}
	ll t=exgcd(b,a%b);
	ll tx=xx,ty=yy;
	xx=ty;
	yy=tx-a/b*ty;
	return t;
}
int main(){
	cin>>x>>y>>m>>n>>l;
	ll a=n-m,b=x-y;
	if(a<0) a=-a,b=-b;
	ll ans=exgcd(a,l);
	if(b%ans!=0){
		cout<<"Impossible"<<endl;
		return 0;
	}else{
		cout<<((xx*b/ans)%(l/ans)+l/ans)%(l/ans)<<endl;
		return 0;
	}
}
