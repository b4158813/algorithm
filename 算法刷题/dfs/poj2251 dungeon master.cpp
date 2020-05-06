#include<cstdio>
#include<iostream>
using namespace std;

char maze[35][35][35];
bool vis[35][35][35];
bool can=false;
int mins;
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int sx,sy,sz,ex,ey,ez;

void dfs(int x,int y,int z,int cnt){
	//vis[x][y][z]=1;
	if(x==ex&&y==ey&&z==ez){
		if(can==false) can=true;
		if(cnt<mins){
			mins=cnt;
			return;
		}
	}
	for(int i=0;i<6;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		int nz=z+dir[i][2];
		if(!vis[nx][ny][nz]&&maze[nx][ny][nz]=='.'){
			vis[nx][ny][nz]=1;
			dfs(nx,ny,nz,cnt+1);
			vis[nx][ny][nz]=0;
		}
	}
	return;
}

int main(){
	int l,r,c;
	while(cin>>l>>r>>c){
		mins=10000000;
		if(l==0&&r==0&&c==0) break;
		for(int i=1;i<=l;i++){
			for(int j=1;j<=r;j++){
				for(int k=1;k<=c;k++){
					cin>>maze[i][j][k];
					if(maze[i][j][k]=='S'){
						sx=i;sy=j;sz=k;
					}
					else if(maze[i][j][k]=='E'){
						ex=i;ey=j;ez=k;
					}
				}
			}
			getchar();
		}
		maze[sx][sy][sz]=maze[ex][ey][ez]='.';
		//cout<<sx<<sy<<sz<<endl<<ex<<ey<<ez<<endl;
		dfs(sx,sy,sz,0);
		if(can&&mins!=10000000) printf("Escaped in %d minute(s).\n",mins);
		else printf("Trapped!\n");
	}
	return 0;
}
