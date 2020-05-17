#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,tot;
priority_queue<ll,vector<ll>,greater<ll>> pq;
int main(){
	scanf("%d",&n);
	tot+=n;
	ll x;
	while(n--){
		scanf("%lld",&x);
		pq.push(x);
	}
	scanf("%d",&n);
	tot+=n;
	while(n--){
		scanf("%lld",&x);
		pq.push(x);
	}
	int pos=((tot+1)>>1)-1;
	while(pos--){
		pq.pop();
	}
	printf("%lld\n",pq.top());
	return 0;
}