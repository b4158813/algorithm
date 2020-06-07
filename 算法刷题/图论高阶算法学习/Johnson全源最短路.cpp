#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3005;
int n,m,ring[maxn],vis[maxn];
ll dis[maxn],hh[maxn];
struct Edge
{
	int u,v,w,next;
}e[maxn<<1];
struct node
{
	int u;
	ll dis;
	bool operator<(const node&rhs)const{
		return dis>rhs.dis;
	}
};
int cnt,head[maxn<<1];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
inline void init_graph(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
inline void dij(int st){
	for(int i=1;i<=n;i++) dis[i]=1e9;
	priority_queue<node> q;
	q.push(node{st,0});
	dis[st]=0;
	while(q.size()){
		node q1=q.top();
		q.pop();
		int u=q1.u;
		ll d=q1.dis;
		if(d>dis[u]) continue;
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v;
			ll w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(node{v,dis[v]});
			}
		}
	}
}
inline bool spfa(int st){
	for(int i=1;i<=n;i++) hh[i]=1e9;
	queue<int> q;
	q.push(st);
	hh[st]=0;
	vis[st]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		ring[u]++;
		if(ring[u]>n) return true;
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v;
			ll w=e[i].w;
			if(hh[v]>hh[u]+w){
				hh[v]=hh[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	init_graph();
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	for(int i=1;i<=n;i++){
		addedge(n+1,i,0);
	}
	if(spfa(n+1)){
		return printf("-1\n"),0;
	}
	for(int u=1;u<=n;u++){
		for(int i=head[u];~i;i=e[i].next){
			e[i].w+=hh[u]-hh[e[i].v];
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		ll ans=0;
		for(int j=1;j<=n;j++){
			if(dis[j]==1e9){
				ans+=j*1e9;
			}else ans+=j*(dis[j]+hh[j]-hh[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}