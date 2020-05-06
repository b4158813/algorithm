#include<iostream>
using namespace std;
int n,a[105];
int vis[105];
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
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
