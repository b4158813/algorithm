#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	int n=10;
	ll x,y;
	while(n--){
		cin>>x>>y;
		cout<<x+y-gcd(x,y)<<endl;
	}
	return 0;
}
