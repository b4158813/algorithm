#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n;
ll sum;
ll f(ll x){
	while(n>0){
		if(n%2==0){
			sum+=(1+n-1)*(n/2)/2;
		}else{
			sum+=(n+1)*(n/2+1)/2;
		}
		n/=2;
	}
	return sum;
}

int main(){
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
