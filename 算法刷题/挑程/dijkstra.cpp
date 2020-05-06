#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
typedef long long ll;

struct Edge{
	int u,v,w,next;
}e[1000005];

int n,m,s,now,cnt,dis[1000005],vis[1000005],head[1000005];

inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dijkstra(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	now=s;
	dis[s]=0;
	while(vis[now]==0){
		int minh=inf;
		vis[now]=1;
		for(int i=head[now];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(!vis[v]&&dis[v]>dis[now]+w){
				dis[v]=dis[now]+w;
			}
		}
		or(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<minh){
				minh=dis[i];
				now=i;
			}
		}
	}
}

int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}
