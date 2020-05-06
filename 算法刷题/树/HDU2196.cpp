#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
	ll v,w,next;
}e[500005];
ll cnt,head[50005];
inline void addedge(ll u,ll v,ll w){
	e[cnt]=Edge{v,w,head[u]};
	head[u]=cnt++;
}
ll n,vis[500005],start;
ll dis[500005],ans;
inline void init(){
	cnt=ans=start=0;
	memset(head,-1,sizeof(head));
	memset(dis,0,sizeof(dis));
}

void dfs(ll x,ll fa,ll len){
	for(ll i=head[x];~i;i=e[i].next){
		ll v=e[i].v,w=e[i].w;
		if(v==fa) continue;
		dfs(v,x,len+w);
		dis[v]=max(dis[v],len+w);
		if(len+w>=ans){
			ans=len+w;
			start=v;
		}
	}
}

int main(){
	while(scanf("%lld",&n)!=EOF){
		init();
		ll u,w;
		for(ll i=2;i<=n;i++){
			scanf("%lld%lld",&u,&w);
			addedge(i,u,w);
			addedge(u,i,w);
		}
		dfs(1,-1,0);
		dfs(start,-1,0);
		dfs(start,-1,0);
		for(ll i=1;i<=n;i++){
			printf("%lld\n",dis[i]);
		}
	}
	return 0;
}
