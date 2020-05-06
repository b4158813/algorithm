#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,temp,sum;
struct node{
	ll rx,rl,rr;
}o[300005];

bool cmp(node x1,node x2){
	if(x1.rl==x2.rl) return x1.rr>x2.rr;
	return x1.rl<x2.rl;
}
ll t;
ll dfs(ll x){
	ll now=o[x].rl,add=1,res=0;
	while(t<n+1&&o[t].rr<=o[x].rr){
		if(o[t].rl!=now) add=0;
		now=o[t].rr;
		res+=dfs(t++);
	}
	if(now!=o[x].rr) add=0;
	return 1+add+res;
}

int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x,y;
		cin>>x>>y;
		o[i].rx = x;
		o[i].rl = x-y;
		o[i].rr = x+y;
	}
	for(int i=2;i<=n;i++){
		if(o[i].rx!=o[i-1].rx) break;
		else if(i==n){
			cout<<n+1<<endl;
			return 0;
		}
	}
	sort(o+1,o+n+1,cmp);
	t=1;
	while(t<n+1){
		sum+=dfs(t++);
	}
	cout<<1+sum<<endl;
	return 0;
}
