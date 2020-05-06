#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
struct Edge{
	int v,next;
}e[500005];

int cnt,head[200005];

inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++; 
}

int n,m,num,deep,low[200005],dfn[200005];
int cut[200005],ans;

void tarjan(int u,int fa){
	low[u]=dfn[u]=++deep;
	int child=0;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v,fa);
			low[u]=min(low[u],low[v]);
			if(u!=fa&&low[v]>=dfn[u])
				cut[u]=1;
			if(u==fa)
				child++;
		}
		low[u]=min(low[u],dfn[v]);
	}
	if(u==fa&&child>=2)
		cut[u]=1;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	int u,v;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	for(int i=1;i<=n;++i)
		if(!dfn[i])
			tarjan(i,i);
	for(int i=1;i<=n;++i)
		if(cut[i])
			ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		if(cut[i])
			printf("%d ",i);
	return 0;
}
