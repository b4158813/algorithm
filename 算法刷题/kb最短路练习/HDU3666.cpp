#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double inf=0x3f3f3f3f;
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
	for(int i=1;i<=n+m+10;i++) dis[i]=inf;
	queue<int> q;
	q.push(st);
	dis[st]=0;
	vis[st]=1;
	while(!q.empty()){
		ll u=q.front();q.pop();
		vis[u]=0;
		ring[u]++;
		if(ring[u]>sqrt(n+m)) return true;
		for(int i=head[u];i!=-1;i=e[i].next){
			ll v=e[i].v;
			double w=e[i].w;
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
	while(~scanf("%d%d%lf%lf",&n,&m,&l,&r)){
		cnt=0;
		l=log2(l);
		r=log2(r);
		memset(head,-1,sizeof(head));
		double x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%lf",&x);
				double temp=log2(x);
				addedge(n+j,i,r-temp);
				addedge(i,n+j,temp-l);
			}
		}
//		for(int i=1;i<=n+m;i++) addedge(0,i,0);
		if(spfa(1)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
