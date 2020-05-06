#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
ll maxn=10005;
const int inf=1e8;
int n,m,k;
ll Max,cnt,head[30005],dis[30005],ring[30005],vis[30005];
struct Edge{
	ll u,v,w,next;
}e[150005];
inline void addedge(ll u,ll v,ll w){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline bool spfa(){
	for(int i=0;i<=Max;i++) dis[i]=-inf;
	queue<int> q;
	q.push(0);
	dis[0]=0;
	vis[0]=1;
	while(!q.empty()){
		ll u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			ll v=e[i].v,w=e[i].w;
			if(dis[v]<dis[u]+w){
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
	scanf("%d",&n);
	ll x,y;
	Max=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x,&y);
		addedge(x,y+1,2);
		Max=max(Max,y+1);
	}
	for(int i=0;i<=Max;i++){
		addedge(i,i+1,0);
		addedge(i+1,i,-1);
	}
	spfa();
	printf("%lld\n",dis[Max]);
	return 0;
}
