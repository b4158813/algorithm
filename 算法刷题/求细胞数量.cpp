#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[105][105];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool vis[105][105];
struct node{
	int x,y;
};
inline bool in(int x,int y){
	return (x<=n&&x>=1&&y<=m&&y>=1);
}
inline void bfs(int x,int y){
	queue<node> q;
	q.push(node{x,y});
	while(q.size()){
		node q1=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int dx=q1.x+dir[i][0];
			int dy=q1.y+dir[i][1];
			if(!vis[dx][dy]&&in(dx,dy)&&a[dx][dy]!='0'){
				vis[dx][dy]=1;
				q.push(node{dx,dy});
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!='0'&&(!vis[i][j])){
				vis[i][j]=1;
				bfs(i,j);
//				printf("%d %d\n",i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
