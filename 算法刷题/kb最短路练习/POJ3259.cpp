#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll; 
const int inf=1e8;
int n,m,k;
struct Edge{
	int u,v,w,next;
}e[50005];
int cnt,head[555],vis[555],ring[555];
ll dis[555];
inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}
inline bool spfa(int st){
	memset(ring,0,sizeof(ring));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=inf;
	queue<int> q;
	dis[st]=0;
	ring[st]=1;
	vis[st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				ring[v]=ring[u]+1;
				if(ring[v]>n) return true;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return false;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		cnt=0;
		memset(head,0,sizeof(head));
		scanf("%d%d%d",&n,&m,&k);
		int u,v,w;
		while(m--){
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		while(k--){
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,-w);
		}
		bool f=false;
		for(int i=1;i<=n;i++){
			if(f) break;
			if(spfa(i)){
				f=true;
			}
		}
		if(!f) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
