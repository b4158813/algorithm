#include<bits/stdc++.h>
using namespace std;

int x[25],ans=0;
int n,k;
bool vis[25];

bool isprime(int a){
	for(int i=2;i*i<=a;i++){
		if(a%i==0) return false;
	}
	return true;
}

void dfs(int as,int sum,int start){
	if(as==k) if(isprime(sum)) {ans++;return;}
	for(int i=start;i<=n;i++){
		dfs(as+1,sum+x[i],i+1);
	}
	return;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	dfs(0,0,1);
	cout<<ans<<endl;;
	return 0;
}
