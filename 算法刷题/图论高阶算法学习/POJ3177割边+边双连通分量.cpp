#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;

struct Edge{
	int v,next;
}e[500005];

int cnt,head[100005];

inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++; 
}

int n,m,num,deep,top,sta[100005],low[100005],dfn[100005],vis[100005],color[100005];

inline void tarjan(int u,int fa){
	vis[sta[++top]=u]=1;
	low[u]=dfn[u]=++deep;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(i==(fa^1)) continue;
		if(!dfn[v]) tarjan(v,i),low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		vis[u]=0;
		color[u]=++num;
		while(sta[top]!=u){
			vis[sta[top]]=0;
			color[sta[top--]]=num;
		}
		top--;
	}
}

int indeg[100005],ans;

inline void init(){
	cnt=ans=deep=num=top=0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(head,-1,sizeof(head));
	memset(indeg,0,sizeof(indeg));
	memset(sta,0,sizeof(sta));
	memset(vis,0,sizeof(vis));
	memset(color,0,sizeof(color));
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		init();
		int u,v;
		for(int i=1;i<=m;++i){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		tarjan(1,-1);
		for(int i=1;i<=n;i++){
			for(int j=head[i];~j;j=e[j].next){
				int v=e[j].v;
				if(color[i]!=color[v]){
					indeg[color[v]]++;
				}
			}
		}
		for(int i=1;i<=num;i++)
			if(indeg[i]==1)
				ans++;
		printf("%d\n",(ans+1)/2); 
	}
	return 0;
}
