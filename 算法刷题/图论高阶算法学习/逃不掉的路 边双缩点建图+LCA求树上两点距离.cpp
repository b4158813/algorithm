#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
struct Edge{
	int v,next;
}e[100005],E[100005];
int n,m,q,cnt,head[100005];
int Cnt,Head[100005];
inline void Addedge(int u,int v){
	E[Cnt]=Edge{v,Head[u]};
	Head[u]=Cnt++;
}
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
int vis[100005],low[100005],dfn[100005],sta[100005],color[100005],top,deep,num;
void tarjan(int u,int fa){
	low[u]=dfn[u]=++deep;
	vis[sta[++top]=u]=1;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}else if(vis[v]) low[u]=min(low[u],dfn[v]);
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
int dis[5005][5005],Vis[100005];
inline void bfs(int x){
	memset(Vis,0,sizeof(Vis));
	queue<int> q;
	dis[x][x]=0;
	Vis[x]=1;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=Head[u];~i;i=E[i].next){
			int v=E[i].v;
			if(!Vis[v]){
				Vis[v]=1;
				dis[x][v]=dis[x][u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	memset(Head,-1,sizeof(Head));
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	tarjan(1,-1);
//	cout<<num<<endl;
	for(int u=1;u<=n;u++){
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v;
			if(color[u]!=color[v]){
				Addedge(color[u],color[v]);
			}
		}
	}
	for(int i=1;i<=num;i++){
		bfs(i);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",dis[color[u]][color[v]]);
	}
	return 0;
}
