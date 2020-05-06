#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1ll<<60;
struct Edge{
	int u,v,w,next;
}e[1000005];

int n,m,head[10005],cnt,vis[10005];
ll dis[10005];
inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline void spfa(int st){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	for(int i=1;i<=n;++i) dis[i]=inf;
	for(int i=head[st];i;i=e[i].next){
		if(e[i].v==st) continue;
		vis[e[i].v]=1;
		dis[e[i].v]=e[i].w;
		q.push(e[i].v);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	while(~scanf("%d",&n)){
		cnt=0;
		memset(head,0,sizeof(head)); 
		int x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&x);
				addedge(i,j,x);
			}
		}
		spfa(1);
		int ans=dis[n],d1=dis[1];
		spfa(n);
		int d2=dis[n];
		printf("%d\n",min(ans,d1+d2));
	}
	return 0;
}


