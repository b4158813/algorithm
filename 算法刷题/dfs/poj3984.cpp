#include<cstdio>
#include<iostream>
using namespace std;

int a[10][10],cnt=1,sum=0,mins=1000000;
bool vis[10][10];
int bx[20],by[20],ex,ey;
int ax[20],ay[20];
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

bool in(int x,int y){
	if(x>=1&&x<=5&&y>=1&&y<=5) return 1;
	return 0;
}
void dfs(int x, int y){
	if(x==ex&&y==ey){
		if(sum<mins){
			mins=sum;
			for(int i=1;i<=mins;i++){
				ax[i]=bx[i];
				ay[i]=by[i];
			}
		}
		return;
	}
	for(int i=0;i<=3;i++){
		//vis[x][y]=1;
		int nx=x+dir[i][0];
		int	ny=y+dir[i][1];
		if(!vis[nx][ny]&&a[nx][ny]==0&&in(nx,ny)){
			vis[nx][ny]=1;
			sum++;
			bx[sum]=nx;
			by[sum]=ny;
			dfs(nx,ny);
			vis[nx][ny]=0;
			--sum;
		}
	}
}

int main(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	ex=5;ey=5;
	dfs(1,1);
	//cout<<mins<<endl;
	printf("(0, 0)\n");
	for(int i=1;i<=mins;i++){
		printf("(%d, %d)\n",ax[i]-1,ay[i]-1);
	}
	return 0;
}
