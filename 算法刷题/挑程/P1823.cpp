#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005];
ll ans[500005];
stack<ll> s;
ll anss;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=1;
	}
	for(ll i=1;i<=n;i++){
		while(!s.empty()&&a[i]>=a[s.top()]){
			anss+=ans[s.top()];
			if(a[s.top()]==a[i]) ans[i]+=ans[s.top()];
			s.pop();
		}
		if(!s.empty()) anss++;
		s.push(i);
	//	cout<<"ans"<<i<<"="<<ans[i]<<endl;
	}
	cout<<anss<<endl;
	return 0;
} //https://www.luogu.com.cn/problem/P1823
