#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > q;

int main(){
	ll n;
	cin>>n;
	ll a;
	for(int i=1;i<=n;i++){
		cin>>a;
		q.push(a);
	}
	ll sum=0;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	else if(n==1){
		cout<<q.top()<<endl;
		return 0;
	}
	while(q.size()>1){
		ll x = q.top();
		q.pop();
		ll y = q.top();
		q.pop();
		ll z = x+y;
		sum+=z;
		q.push(z);
	}
	cout<<sum<<endl;
	return 0;
}
