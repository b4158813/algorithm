#include<cstdio>
#include<cmath>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

struct Edge{
	int v,next;
}e[100005],ee[100005];

int cnt,ccnt,hhead[10005],head[10005];

inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++; 
}

inline void aaddedge(int u,int v){
	ee[ccnt]=Edge{v,hhead[u]};
	hhead[u]=ccnt++;
}
int n,m,num,deep,top,sta[10005],low[10005],dfn[10005],vis[10005],color[10005];
int val[10005],vval[10005];

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
		vval[num]+=val[u];
		while(sta[top]!=u){
			vis[sta[top]]=0;
			vval[num]+=val[sta[top]];
			color[sta[top--]]=num;
		}
		top--;
	}
}

int indeg[10005],tpx[10005],tp;

inline void toposort(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		tpx[++tp]=u;
		for(int i=hhead[u];~i;i=ee[i].next){
			int v=ee[i].v;
			if(indeg[v]){
				indeg[v]--;
				if(indeg[v]==0){
					q.push(v);
				}
			}
		}
	}
}

int dp[10005],ans;
bool vvis[10005];

void dfs(int x){
	dp[x]=vval[x];
	int temp=0;
	for(int i=hhead[x];~i;i=ee[i].next){
		int v=ee[i].v;
		if(!vvis[v]) vvis[v]=1,dfs(v);
		temp=max(temp,dp[v]);
	}
	dp[x]+=temp;
}

int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	memset(hhead,-1,sizeof(hhead));
	for(int i=1;i<=n;++i) scanf("%d",&val[i]);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;++u){
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v;
			if(color[u]!=color[v]){
				aaddedge(color[u],color[v]);
				indeg[color[v]]++;
			}
		}
	}
	toposort();
	for(int i=1;i<=num;++i){
		int now=tpx[i];
		if(!vvis[now]){
			dfs(now);
			ans=max(ans,dp[now]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
