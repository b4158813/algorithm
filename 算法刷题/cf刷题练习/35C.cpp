#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,m,k,x,y,dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int vis[2005][2005],ans,ansx,ansy;
struct node{
	int x,y,step;
};
queue<node> q;
inline bool in(int x,int y){
	return (x>=1&&x<=n&&y>=1&&y<=m);
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
    	scanf("%d%d",&x,&y);
    	vis[x][y]=1;
    	q.push(node{x,y,0});
	}
	while(q.size()){
		node q1=q.front();
		q.pop();
		ansx=q1.x,ansy=q1.y;
		for(int i=0;i<4;i++){
			int dx=q1.x+dir[i][0];
			int dy=q1.y+dir[i][1];
			if(!vis[dx][dy]&&in(dx,dy)){
				vis[dx][dy]=1;
				q.push(node{dx,dy,q1.step+1});
			}
		}
	}
	printf("%d %d\n",ansx,ansy);
	fclose(stdin);
	fclose(stdout);
    return 0;
}

