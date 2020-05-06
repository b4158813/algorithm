#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const ll inf=1ll<<60;
const ll mod=1e9+7;
inline ll read() { 
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}
struct Edge{
	ll v,next;
}e[300005];
ll cnt,head[200005];
void addedge(ll u,ll v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
ll n,m,ans[200005],Val[200005],val[200005],top,num,deep,sta[200005],vis[200005],low[200005],dfn[200005],color[200005];
void tarjan(ll u){
	vis[sta[++top]=u]=1;
	low[u]=dfn[u]=++deep;
	for(ll i=head[u];~i;i=e[i].next){
		ll v=e[i].v;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		vis[u]=0;
		color[u]=++num;
		Val[num]=min(Val[num],val[u]);
		while(sta[top]!=u){
			vis[sta[top]]=0;
			Val[num]=min(Val[num],val[sta[top]]);
			color[sta[top--]]=num;
		}
		top--;
	}
}
inline void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
	for(ll i=1;i<=n+15;i++) Val[i]=inf;
}

int main(){
	n=read();
	init();
	for(ll i=1;i<=n;i++) val[i]=read();
	m=read();
	for(ll i=1;i<=m;i++){
		ll u,v;
		u=read(),v=read();
		addedge(u,v);
	}
	for(ll i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(ll i=1;i<=n;i++){
		if(val[i]==Val[color[i]]) ans[color[i]]=(ans[color[i]]+1)%mod;
	}
	ll Ans1=1,Ans2=0;
	for(ll i=1;i<=num;i++){
		Ans1=(Ans1*ans[i])%mod;
		Ans2=Ans2+Val[i];
	}
	printf("%lld %lld\n",Ans2,Ans1%mod);
	return 0;
}
