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
}e[800005];
ll cnt,head[200005];
void addedge(ll u,ll v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
ll n,p,m,top,num,deep,Val[200005],val[200005],sta[200005],vis[200005],low[200005],dfn[200005],color[200005];
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
	for(int i=1;i<=n;i++) val[i]=inf,Val[i]=inf;
}
ll indeg[200005],outdeg[200005];
int main(){
	n=read();
	init();
	ll v;
	for(int i=1;i<=n;i++){
		while(~scanf("%lld",&v)){
			if(v==0) break;
			addedge(i,v);
		}
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;u++){
		for(int i=head[u];~i;i=e[i].next){
			ll v=e[i].v;
			if(color[u]!=color[v]){
				indeg[color[v]]++;
				outdeg[color[u]]++;
			}
		}
	}
	ll ans1=0,ans2=0;
	for(int i=1;i<=num;i++){
		if(indeg[i]==0) ans1++;
		if(outdeg[i]==0) ans2++;
	}
	if(num==1)printf("1\n0\n");
	else printf("%lld\n%lld\n",ans1,max(ans1,ans2));
	return 0;
}
