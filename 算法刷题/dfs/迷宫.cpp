#include<bits/stdc++.h>
using namespace std;

int n,m,k=0,ans=0;
int xy[100][100],ax,ay,bx,by;
int nx,ny,dxy[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int p[10000][5];
bool vis[100][100];
//stack<int> s;

void dfs(int x, int y){
	if(x==bx&&y==by){
		if(ans==0) ans=1;
		for(int j=0;j<k;j++){
			printf("(%d,%d)",p[j][0],p[j][1]);
			cout<<"->";
		}
		printf("(%d,%d)\n",bx,by);
		return;
	}
	for(int i=0;i<4;i++){
		if(!vis[x+dxy[i][0]][y+dxy[i][1]]&&xy[x+dxy[i][0]][y+dxy[i][1]]==1){
			p[k][0]=x;
			p[k][1]=y;
			vis[x][y]=1;
			k++;
			dfs(x+dxy[i][0],y+dxy[i][1]);
			vis[x][y]=0;
			k--;
		}
	}
}

int main()
{	
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>xy[i][j];
		}
	}
	cin>>ax>>ay;
	cin>>bx>>by;
	dfs(ax,ay);
	if(ans==0) cout<<"-1"<<endl;
	return 0;
}
