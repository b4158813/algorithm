#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
struct Edge{
	int v,next;
}e[50005];
int cnt,head[10005];
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++; 
}
int n,m,num,deep,top,sta[10005],low[10005],dfn[10005],vis[10005],color[10005];
int Size[10005],chu[50005],ccnt,ans;
inline void tarjan(int u){
	vis[sta[++top]=u]=1;
	low[u]=dfn[u]=++deep;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
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
int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	int u,v;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		Size[color[i]]++;
		for(int j=head[i];~j;j=e[j].next){
			int v=e[j].v;
			if(color[v]!=color[i]) chu[color[i]]++;
		}
	}
	for(int i=1;i<=num;i++){
		if(chu[i]==0) ccnt++,ans=Size[i];
	}
	printf("%d\n",ccnt==1?ans:0);
	return 0;
}
