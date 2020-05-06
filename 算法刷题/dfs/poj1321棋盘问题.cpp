#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 1005;
int cnt=0;
int n,k;
char q[maxn][maxn];
bool vis[maxn];

void dfs(int x,int sum){
	if(sum>k){
		cnt++;
		return;
	}
	for(int i=x;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[j]&&q[i][j]=='#'){
				vis[j]=1;
				dfs(i+1,sum+1);
				vis[j]=0;
			}
		}
	}
}

int main(){
	
	while(cin>>n>>k){
		cnt=0;
		if(n==-1&k==-1) break;
		//memset(q,'.',sizeof(q));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>q[i][j];
			}
		}
		dfs(1,1);//the first chess
		cout<<cnt<<endl;
	}
	return 0;
}
