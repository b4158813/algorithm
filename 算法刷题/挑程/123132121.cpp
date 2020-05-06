#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char a[105][105];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int vis[105][105];
struct node{
	int x,y,step;
};

inline void bfs(int x, int y){
	queue<node> q;
	node ne;
	ne.x=x,ne.y=y;
	ne.step=0;
	vis[x][y]=1;
	q.push(ne);
	while(!q.empty()){
		node q1 = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int dx=q1.x+dir[i][0];
			int dy=q1.y+dir[i][1];
			if(a[dx][dy]=='.'&&!vis[dx][dy]&&dx>=1&&dx<=n&&dy>=1&&dy<=m){
				node v;
				vis[dx][dy]=1;
				v.x=dx;
				v.y=dy;
				v.step=q1.step+1;
				ans=max(ans,v.step);
				q.push(v);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			memset(vis,0,sizeof(vis));
			if(a[i][j]=='.') bfs(i,j);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
