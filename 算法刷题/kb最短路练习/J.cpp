#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1ll<<50;
inline ll read() {
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}
int cnt,head[800005],pre[800005],num,ans[800005];
ll dis[800005];
int vis[800005];
int n,m,k;
struct Edge{
	int u,v,w,id,next;
}e[800005]; 
struct node{
	int u;
	ll dis;
	bool operator<(const node&rhs)const {
		return dis>rhs.dis;
	}
};

inline void addedge(int u,int v,int w,int id){
	e[++cnt]=Edge{u,v,w,id,head[u]};
	head[u]=cnt;
}

inline void dij(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	priority_queue<node> q;
	q.push(node{1,0});
	while(!q.empty()){
		node q1=q.top();q.pop();
		ll u=q1.u,d=q1.dis;
		if(d>dis[u])continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+1ll*w){
				dis[v]=dis[u]+1ll*w;
				q.push(node{v,dis[v]});
				pre[v]=u;
			}
		}
	}
}

inline void bfs(){
	queue<int> q;
	q.push(1);
	if(num==n||num==k) return;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			if(pre[v]==u){
				ans[++num]=e[i].id;
				q.push(v);
				if(num==n||num==k) return;
			}
		}
	}
}

int main(){
	n=read(),m=read(),k=read();
	int u,v,w;
	for(int i=1;i<=m;++i){
		u=read(),v=read(),w=read();
		addedge(u,v,w,i);
		addedge(v,u,w,i);
	}
	dij();
	bfs();
	printf("%d\n",num);
	for(int i=1;i<=num;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
