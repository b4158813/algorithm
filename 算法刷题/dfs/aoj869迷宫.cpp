#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
char map1[maxn][maxn];
int ans,n,tx,ty;
bool vis[maxn][maxn];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

void dfs(int x, int y){
	if(vis[x][y]||x<1||x>n||y<1||y>n||map1[x][y]=='#') return;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		dfs(nx,ny);
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>map1[i][j];
	}
	dfs(1,1);
//  dfs(n,n);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<vis[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(vis[i][j]){
				for(int k=0;k<4;k++){
					tx=i+dir[k][0];
					ty=j+dir[k][1];
					if(vis[tx][ty]==0) ans++;
				}
			}
		}
	}
	cout<<(ans-4)*9<<endl;
	return 0;
}
