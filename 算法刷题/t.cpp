#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=500005;
struct Edge{
	int u,v,w,next;
}e[M];
int dfn[N],low[N],sta[N],deep,num,top,vis[N],color[N],Size[N];
int n,m,cnt,head[N];
inline void init(){
	n=cnt=deep=num=top=0;
	memset(head,-1,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	memset(sta,0,sizeof(sta));
	memset(color,0,sizeof(color));
	memset(Size,0,sizeof(Size));
}
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}

inline void tarjan(int u,int fa){
	vis[sta[++top]=u]=1;
	low[u]=dfn[u]=++deep;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(i==(fa^1)) continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		vis[u]=0;
		color[u]=++num;
		Size[num]++;
		while(sta[top]!=u){
			vis[sta[top]]=0;
			color[sta[top--]]=num;
			Size[num]++;
		}
		top--;
	}
}


int main() {
	while(scanf("%d",&m)!=EOF){
		init();
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
			n=max(n,max(v,u));
		}
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,-1);
		int ans=0;
		for(int i=1;i<=num;i++){
//			printf("scc%d:%d\n",i,Size[i]);
			ans=max(ans,Size[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}
