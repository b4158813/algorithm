#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e9;
int n,m,k;
double l,r;
ll cnt,head[600005],ring[600005],vis[600005];
ll dis[600005];
struct Edge{
	ll u,v,w,next;
}e[3500005];
inline void addedge(ll u,ll v,ll w){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline bool spfa(int st){
	memset(vis,0,sizeof(vis));
	memset(ring,0,sizeof(ring));
	for(int i=1;i<=n;i++) dis[i]=inf;
	queue<int> q;
	q.push(st);
	dis[st]=0;
	vis[st]=1;
	while(!q.empty()){
		ll u=q.front();q.pop();
		vis[u]=0;
		ring[u]++;
		if(ring[u]>n) return true;
		for(ll i=head[u];i!=-1;i=e[i].next){
			ll v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
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
		scanf("%d%d",&n,&m);
		cnt=0;
		memset(head,-1,sizeof(head));
		ll u,v,w;
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&u,&v,&w);
			addedge(u,v,w);
			if(w>=0) addedge(v,u,w);
		}
		if(spfa(1)) printf("YE5\n");
		else printf("N0\n");
	}
	return 0;
}
