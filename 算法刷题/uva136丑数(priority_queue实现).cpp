#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
priority_queue <ll,vector<ll>,greater<ll> > pq;
set <ll> s;

int main(){
	ll ans;
	pq.push(1);s.insert(1);
	for(int i=1;;i++){
		ans = pq.top();
		pq.pop();
		if(i==1500){ //到1500个的时候停止并输出 
			cout<<"The 1500'th ugly number is "<<ans<<"."<<endl;
			break;
		}
		ll k1=ans*2,k2=ans*3,k3=ans*5;
		//去重措施：如果在集合里，则表明算过了，就不用加到队列里去 
		if(!s.count(k1)) {pq.push(k1);s.insert(k1);}
		if(!s.count(k2)) {pq.push(k2);s.insert(k2);}
		if(!s.count(k3)) {pq.push(k3);s.insert(k3);}
	}
	return 0;
}
