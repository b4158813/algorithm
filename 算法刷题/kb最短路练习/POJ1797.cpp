#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=2147483647;
typedef long long ll;

int n,m,now,dis[1005],mmp[1005][1005];
int vis[1005];

inline void dijkstra(){
	for(int i=1;i<=n;i++){
		dis[i]=mmp[1][i];
	}
	vis[1]=1;
	while(1){
		int maxh=-1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]>maxh){
				maxh=dis[i];
				now=i;
			}
		}
		if(maxh==-1) return;
		vis[now]=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<min(dis[now],mmp[now][i])){
				dis[i]=min(dis[now],mmp[now][i]);
			}
		}
	}
}

int main(){
	int t;cin>>t;
	for(int o=1;o<=t;o++){
		memset(mmp,0,sizeof(mmp));
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			mmp[u][v]=mmp[v][u]=w;
		}
		dijkstra();
		printf("Scenario #%d:\n%d\n\n",o,dis[n]);
	}
	return 0;
}
