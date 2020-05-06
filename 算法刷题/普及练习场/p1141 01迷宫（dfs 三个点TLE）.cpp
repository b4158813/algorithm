#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[1005][1005];
int dir[4][2]={{0,-1},{1,0},{-1,0},{0,1}};
int ans=0;
int res[1005][1005];
int nxy[1000005][2];

void dfs(int x,int y){
	ans++;
	nxy[ans][0]=x;
	nxy[ans][1]=y;
	res[x][y]=1;
	
	for(int i=0;i<4;i++){
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(dx<=0||dx>n||dy<=0||dy>n){
			continue;
		}
		if(res[dx][dy]) continue;
		if(s[dx][dy]!=s[x][y]){
			dfs(dx,dy);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	memset(res,0,sizeof(res));
	while(m--){
		int i,j;
		cin>>i>>j;
		ans=0;
		if(res[i][j]){
			cout<<res[i][j]<<endl;
			continue;
		}
		dfs(i,j);
		for(int k=1;k<=ans;k++){
			res[nxy[k][0]][nxy[k][1]]=ans;
		}
		cout<<res[i][j]<<endl;
	}
	return 0;
}
