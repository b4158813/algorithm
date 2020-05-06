#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
ll a[100005];
stack<ll> s;
ll ans[100005];
int main(){
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=1;
	}
	
	for(ll i=n;i>=1;i--){
		while(!s.empty()&&a[i]>a[s.top()]){
			ans[i]+=ans[s.top()];
			s.pop();
		}
		s.push(i);
	}
	ll anss=0;
	for(ll i=1;i<=n;i++) anss+=ans[i];
	cout<<anss-n<<endl;
	return 0;
}
