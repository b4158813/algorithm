#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1e9;
int n,m,k;
double l,r;
ll cnt,head[600005],ring[600005],vis[600005];
double dis[600005];
struct Edge{
	ll u,v,next;
	double w;
}e[3500005];
inline void addedge(ll u,ll v,double w){
	e[++cnt]=Edge{u,v,head[u],w};
	head[u]=cnt;
}

inline bool spfa(int st){
	memset(vis,0,sizeof(vis));
	memset(ring,0,sizeof(ring));
	for(int i=0;i<=n+m+10;i++) dis[i]=1e40;
	queue<int> q;
	q.push(st);
	dis[st]=0;
	ring[st]=1;
	vis[st]=1;
	while(!q.empty()){
		ll u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=e[i].next){
			ll v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				ring[v]=ring[u]+1;
				if(ring[v]>=(int)sqrt(n+m)) return true;
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
	while(~scanf("%d%d%lf%lf",&n,&m,&l,&r)){
		cnt=0;
		memset(head,-1,sizeof(head));
		double x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;++j){
				scanf("%lf",&x);
				addedge(n+j,i,log(r/x));
				addedge(i,n+j,-log(l/x));
			}
		}
		for(int i=1;i<=n;i++) addedge(0,i,0);
		if(spfa(0)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
