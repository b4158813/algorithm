#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,x,y;
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
	cin>>a>>b;
	exgcd(a,b);
	cout<<(x%b+b)%b<<endl;
	return 0;
}
