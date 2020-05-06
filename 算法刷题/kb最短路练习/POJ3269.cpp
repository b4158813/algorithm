#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int inf=1e8;
int n,m,k;
ll cnt,head[30005],dis[30005],ring[30005],vis[30005];
struct Edge{
	ll u,v,w,next;
}e[150005];
inline void addedge(ll u,ll v,ll w){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline bool spfa(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	queue<int> q;
	q.push(1);
	ring[1]=1;
	dis[1]=0;
	vis[1]=1;
	while(!q.empty()){
		ll u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			ll v=e[i].v,w=e[i].w;
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
	scanf("%d%d%d",&n,&m,&k);
	ll x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		addedge(x,y,z);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		addedge(y,x,-z);
	}
	if(spfa()) printf("-1\n");
	else{
		printf("%lld\n",dis[n]>=inf?-2:dis[n]);
	}
	return 0;
}
