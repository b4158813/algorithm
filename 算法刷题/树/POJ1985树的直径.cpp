#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct Edge{
	int v,w,next;
}e[500005];
int cnt,head[500005];
inline void addedge(int u,int v,int w){
	e[cnt]=Edge{v,w,head[u]};
	head[u]=cnt++;
}
inline void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

int n,m,start,dis[50005],ans;

void dfs(int x,int fa,int len){
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v,w=e[i].w;
		if(v==fa) continue;
		dfs(v,x,len+w);
		dis[v]=max(dis[v],len+w);
		if(len+w>=ans){
			ans=len+w;
			start=v;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	int u,v,w;
	char c;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%c",&u,&v,&w,&c);
		getchar();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dfs(1,-1,0);
	dfs(start,-1,0);
	printf("%d\n",ans);
	return 0;
}
