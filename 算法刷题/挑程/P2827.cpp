#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f;
ll n,m,q,t,ans2[9000005],ans[9000005];
double u,v;
priority_queue<ll> q1;
queue<ll> q2,q3;

ll getmax(){
	ll max1=-inf,max2=max1,max3=max1;
	if(!q1.empty()) max1 = q1.top();
	if(!q2.empty()) max2 = q2.front();
	if(!q3.empty()) max3 = q3.front();
	if(max1>=max2&&max1>=max3) {
		q1.pop();
		return max1;
	}else if(max2>=max1&&max2>=max3){
		q2.pop();
		return max2;
	}else{
		q3.pop();
		return max3;
	}
}

int main(){
	cin>>n>>m>>q>>u>>v>>t;
	ll x;
	for(ll i=1;i<=n;i++){
		cin>>x;
		q1.push(x);
	}
	ll tim=0;
	for(ll i=1;i<=m;i++){
		ans[i] = getmax()+tim;
		ll t1=ans[i]*u/v;
		ll t2=ans[i]-t1;
		tim+=q;
		if(t1<t2) swap(t1,t2);
		q2.push(t1-tim);
		q3.push(t2-tim);
	}
	ll cnt=0;
	while(!q1.empty()||!q2.empty()||!q3.empty()){
		ans2[++cnt]=getmax()+tim;
	}
	for(ll i=t;i<=m;i+=t) cout<<ans[i]<<" ";
	cout<<endl;
	for(ll i=t;i<=cnt;i+=t) cout<<ans2[i]<<" ";
	return 0;
}
