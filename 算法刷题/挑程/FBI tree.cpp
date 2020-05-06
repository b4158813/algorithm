#include<bits/stdc++.h>
using namespace std;

char s[30000];
int len,n;
char cd[30000];

void check(int x){
	if(cd[2*x]==cd[2*x+1]){
		cd[x]=cd[2*x];
	}else{
		cd[x]='F';
	}
}

void dfs(int x){
	if(x>(1<<(n+1))-1) return;
	dfs(2*x);
	dfs(2*x+1);
	cout<<cd[x];
}

int main(){
	cin>>n;
	for(int i=1;i<=(1<<n);i++) cin>>s[i];
	for(int i=1;i<=(1<<n);i++){
		if(s[i]=='1') cd[(1<<n)-1+i]='I';
		if(s[i]=='0') cd[(1<<n)-1+i]='B';
	}
	for(int i=(1<<n)-1;i>=1;i--){
		check(i);
	}
	dfs(1);
	return 0;
}
