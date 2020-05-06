#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
//vector <int> v;
long long f[maxn];

long long dfs(int x){
	if(x==1) return 1;
	f[1]=1;
	long long tot=1;
	for(int i=2;i<=x;i++){
		if(i%2!=0) f[i] = f[i-1];
		else {
			f[i]=f[i-1]+f[i/2];
		}
	}
	return f[x];
}

int main(){
	int x;
	cin>>x;
	cout<<dfs(x);
	return 0;
}
