#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[100005];
ll ans1[100005],ans2[100005];
ll ans;
stack<ll> s;
int main(){
	ll n;
	while(cin>>n&&n){
		ans=0;
		while(!s.empty()) s.pop();
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ans1[i]=ans2[i]=1;
		}
		for(ll i=1;i<=n;i++){
			while(!s.empty()&&a[i]<=a[s.top()]){
				ans1[i]+=ans1[s.top()];
				s.pop();
			}
			s.push(i);
		}
		while(!s.empty()) s.pop();
	//	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		for(ll i=n;i>=1;i--){
			while(!s.empty()&&a[i]<=a[s.top()]){
				ans2[i]+=ans2[s.top()];
				s.pop();
			}
			s.push(i);
		}
	//	for(int i=1;i<=n;i++) cout<<ans2[i]<<" ";
		for(ll i=1;i<=n;i++){
			ans1[i]=(ans1[i]+ans2[i]-1)*a[i];
			ans=max(ans1[i],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
} //https://vjudge.net/problem/POJ-2559 
