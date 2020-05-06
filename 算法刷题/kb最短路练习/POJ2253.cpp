#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=2147483647;
typedef long long ll;

struct node{
	double x,y;
}point[300];

int n,m,now;
int vis[1005];
double dis[1005],mmp[1005][1005];

inline void dijkstra(){
	for(int i=1;i<=n;i++){
		dis[i]=mmp[1][i];
	}
	vis[1]=1;
	while(1){
		int minh=inf;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<minh){
				minh=dis[i];
				now=i;
			}
		}
		if(minh==inf) return;
		vis[now]=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]>max(dis[now],mmp[now][i])){
				dis[i]=max(dis[now],mmp[now][i]);
			}
		}
	}
}

inline double get_dis(int i,int j){
	double dx=point[i].x-point[j].x;
	double dy=point[i].y-point[j].y;
	return sqrt(dx*dx+dy*dy);
}

int main(){
	int cnt=0;
	while(cin>>n&&n!=0){
		memset(point,0,sizeof(point));
		memset(mmp,0,sizeof(mmp));
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			double x,y;
			cin>>point[i].x>>point[i].y;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				mmp[i][j]=mmp[j][i]=get_dis(i,j);
			}
		}
		dijkstra();
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++cnt,dis[2]);
	}
	return 0;
}
