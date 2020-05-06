#include<bits/stdc++.h>
using namespace std;

int n,m,t,sx,sy,fx,fy;
int zx,zy;
int maze[10][10];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[10][10];
int ans=0;

void dfs(int x,int y){
	if(x==fx&&y==fy&&maze[x][y]) {
		ans++;
		return;
	}
	if(x<1||x>n||y<1||y>n||maze[x][y]==0) return;
	for(int i=0;i<4;i++){
		if(!vis[x][y]){
			vis[x][y]=1;
			dfs(x+dir[i][0],y+dir[i][1]);
			vis[x][y]=0;
		}
	}
}

int main(){
	memset(maze,1,sizeof(maze));
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	for(int i=1;i<=t;i++){
		cin>>zx>>zy;
		maze[zx][zy]=0;
	}
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}
