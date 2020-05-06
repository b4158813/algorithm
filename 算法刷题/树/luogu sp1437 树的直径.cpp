#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f;
int n,m,cnt,head[500005];
struct Edge{
	int u,v,w,next;
}e[500005];
inline void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
int start,ans,dis[500005];
bool vis[500005];
void dfs(int x){
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v,w=e[i].w;
		if(!vis[v]){
			vis[v]=1;
			dis[v]=dis[x]+w;
			if(dis[v]>ans){
				start=v;
				ans=dis[v];
			}
			dfs(v);
		}
	}
}

int main(){
	scanf("%d",&n);
	int u,v,w;
	init();
	char mei;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v,1);
		addedge(v,u,1);
	}
	dis[1]=0;
	dfs(1);
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	ans=0;
	dis[start]=0;
	dfs(start);
	printf("%d\n",ans);
	return 0;
}
