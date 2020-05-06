#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[1005][1005];
int vis[1005][1005];
int dir[4][2]={{0,-1},{1,0},{-1,0},{0,1}};
int ans=0;

void dfs(int x,int y){
	if(vis[x][y]) ans++;
	if(x<=0||x>n||y<=0||y>n){
		return;
	}
	if(s[x][y]=='1'){
		for(int i=0;i<4;i++){
			int dx=x+dir[i][0];
			int dy=y+dir[i][1];
			if(!vis[dx][dy]&&s[dx][dy]=='0'){
				vis[dx][dy]=1;
				dfs(dx,dy);
			}
		}
	}else if(s[x][y]=='0'){
		for(int i=0;i<4;i++){
			int dx=x+dir[i][0];
			int dy=y+dir[i][1];
			if(!vis[dx][dy]&&s[dx][dy]=='1'){
				vis[dx][dy]=1;
				dfs(dx,dy);
			}
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
	while(m--){
		int i,j;
		cin>>i>>j;
		ans=0;
		memset(vis,0,sizeof(vis));
		vis[i][j]=1;
		dfs(i,j);
		cout<<ans<<endl;
	}
	return 0;
}
