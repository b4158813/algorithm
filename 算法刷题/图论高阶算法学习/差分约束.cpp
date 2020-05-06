#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue> 
using namespace std;
const int inf=1<<30;
struct Edge{
	int u,v,w,next;
}e[50005];
int n,m,cnt,head[50005];
inline void addedge(int u,int v,int w){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
int dis[50005],ring[50005],vis[50005];
inline bool spfa(){
	for(int i=0;i<=n;i++)dis[i]=inf;
	queue<int> q;
	q.push(0);
	vis[0]=1;
	dis[0]=0;
	while(q.size()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				ring[v]=ring[u]+1;
				if(ring[v]>n) return false;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		} 
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) addedge(0,i,0);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(v,u,w);
	}
	if(spfa()){
		for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	}else{
		printf("NO\n");
	}
	return 0;
} 
