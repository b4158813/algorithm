#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int x1,y1,x2,y2;
int dir[12][2]={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1},{2,2},{-2,2},{2,-2},{-2,-2}};
bool vis[2005][2005];
struct node{
	int x,y,step;
};
inline bool in(int x,int y){
	return (x>=1&&y>=1);
}
inline int bfs(int x,int y){
	memset(vis,0,sizeof(vis));
	queue<node> q;
	q.push(node{x,y,0});
	vis[x][y]=1;
	while(!q.empty()){
		node q1=q.front();
		q.pop();
		if(q1.x==1&&q1.y==1){
			return q1.step;
		}
		for(int i=0;i<12;i++){
			int dx=q1.x+dir[i][0];
			int dy=q1.y+dir[i][1];
			if(!vis[dx][dy]&&in(dx,dy)){
				vis[dx][dy]=1;
				q.push(node{dx,dy,q1.step+1});
			}
		}
	}
}
int main(){
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);
	printf("%d\n",bfs(x1,y1));
	printf("%d\n",bfs(x2,y2));
	return 0;
}
