#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<iostream>
#define re register
using namespace std;
typedef long long ll;
const ll inf=1ll<<50;
const ll mod=1e9+7;
inline ll read() { 
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}
struct Edge{
	ll v,w,next;
}e[500015],E[500015];
ll cnt,head[500015];
ll Cnt,Head[500015];
inline void addedge(ll u,ll v,ll w=0){
	e[cnt]=Edge{v,w,head[u]};
	head[u]=cnt++;
}
inline void Addedge(ll u,ll v,ll w){
	E[Cnt]=Edge{v,w,Head[u]};
	Head[u]=Cnt++;
}

ll n,m,s,S,p,top,num,deep,jiu[500015],Jiu[500015],Val[500015],val[500015],sta[500015],vis[500015],low[500015],dfn[500015],color[500015];
void tarjan(ll u){
	vis[sta[++top]=u]=1;
	low[u]=dfn[u]=++deep;
	for(re ll i=head[u];~i;i=e[i].next){
		ll v=e[i].v;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		vis[u]=0;
		color[u]=++num;
		Val[num]+=val[u];
		if(u==s) S=num;
		if(jiu[u]==1) Jiu[num]=1;
		while(sta[top]!=u){
			vis[sta[top]]=0;
			Val[num]+=val[sta[top]];
			if(sta[top]==s) S=num;
			if(jiu[sta[top]]==1) Jiu[num]=1;
			color[sta[top--]]=num;
		}
		top--;
	}
}
inline void init(){
	cnt=0;
	memset(Head,-1,sizeof(head));
	memset(head,-1,sizeof(head));
}
ll Dis[500015],Vis[500015];
inline void dij(){
	queue<ll> q;
	Dis[S]=Val[S];
	q.push(S);
	Vis[S]=1;
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		Vis[u]=0;
		for(re ll i=Head[u];~i;i=E[i].next){
			ll v=E[i].v,w=E[i].w;
			if(Dis[v]<Dis[u]+w){
				Dis[v]=Dis[u]+w;
				if(Vis[v]==0){
					Vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	n=read(),m=read();
	init();
	ll u,v;
	for(re int i=1;i<=m;++i){
		u=read(),v=read();
		addedge(u,v);
	}
	for(re int i=1;i<=n;++i) val[i]=read();
	s=read(),p=read();
	for(re int i=1;i<=p;++i){
		u=read();
		jiu[u]=1;
	}
	for(re int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	
	for(re int u=1;u<=n;++u){
		for(re int i=head[u];~i;i=e[i].next){
			ll v=e[i].v;
			if(color[u]!=color[v]){
				Addedge(color[u],color[v],Val[color[v]]);
			}
		}
	}
	dij();
	ll ans=0;
	for(re int i=1;i<=num;++i){
		if(Jiu[i]==1){
			ans=max(ans,Dis[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
