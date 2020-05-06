#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1ll<<60;
inline ll read() { 
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}

struct Edge{
	int u,v,w,next;
}e[1000005];

int t,n,m,q,head[10005],cnt,vis[10005],ring[10005],reach[10005];
ll dis[10005],val[10005];
inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline void spfa(){
	memset(vis,0,sizeof(vis));
	memset(ring,0,sizeof(ring));
	for(int i=1;i<=n;++i) dis[i]=inf;
	queue<int> q;
	vis[1]=1;
	ring[1]=1;
	dis[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			ll cha=val[v]-val[u];
			if(dis[u]+cha*cha*cha<dis[v]){
				dis[v]=dis[u]+cha*cha*cha;
				ring[v]=ring[u]+1;
				if(ring[v]>n){
					return;
				}
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	t=read();
	int orz=0;
	while(t--){
		cnt=0;
		memset(head,0,sizeof(head));
		n=read();
		for(int i=1;i<=n;++i) val[i]=read();
		m=read();
		int u,v;
		for(int i=1;i<=m;++i){
			u=read(),v=read();
			addedge(u,v);
		}
		spfa();
		q=read();
		printf("Case %d:\n",++orz);
		for(int i=1;i<=q;++i){
			v=read();
			if(dis[v]<3||dis[v]>inf/2){
				printf("?\n");
			}else{
				printf("%lld\n",dis[v]);
			}
		}
	}
	return 0;
} //https://vjudge.net/problem/LightOJ-1074
