#include<bits/stdc++.h>
using namespace std;
int n,a[15],vis[15];

void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;++i)
			printf("%5d",a[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}

int main(){
	cin>>n;
	dfs(1);
	return 0;
}
