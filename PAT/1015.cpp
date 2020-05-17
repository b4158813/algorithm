#include<bits/stdc++.h>
using namespace std;

int n,d;

inline int qpow(int x,int y){
	int base=x,ans=1;
	while(y){
		if(y&1) ans*=base;
		base*=base;
		y>>=1;
	}
	return ans;
}

inline bool isp(int x){
	if(x==1||x==0) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

inline bool solve(int n,int d){
	if(isp(n)){
		queue<int> q;
		while(n){
			q.push(n%d);
			n/=d;
		}
		int ans=0;
		while(q.size()){
			ans+=q.front()*qpow(d,q.size()-1);
			q.pop();
		}
		// cout<<ans<<endl;
		if(isp(ans)) return true;
		else return false;
	}
	return false;
}
int main(){
	while(cin>>n){
		if(n<0) break;
		cin>>d;
		if(solve(n,d)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}