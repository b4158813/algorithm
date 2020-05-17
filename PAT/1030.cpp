#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1<<30;
const int maxn=505;
struct Edge{
	int u,v,w,cost,next;
}e[maxn<<1];
struct node
{
	int u;
	ll dis;
	bool operator<(const node &rhs)const{
		return dis>rhs.dis;
	}
};
int gcnt,head[maxn];
inline void init_graph(){
	gcnt=0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int w=0,int cost=0){
	e[gcnt]=Edge{u,v,w,cost,head[u]};
	head[u]=gcnt++;
}
int n,m,s,t,pre[maxn];
ll dis[maxn],cost[maxn];

inline void dij(){
	priority_queue<node> q;
	for(int i=1;i<=n;i++) dis[i]=inf,cost[i]=inf;
	q.push(node{s,0});
	dis[s]=cost[s]=0;
	while(q.size()){
		node q1=q.top();
		q.pop();
		int u=q1.u,d=q1.dis;
		if(d>dis[u]) continue;
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v,w=e[i].w,co=e[i].cost;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				cost[v]=cost[u]+co;
				pre[v]=u;
				q.push(node{v,dis[v]});
			}else if(dis[v]==dis[u]+w&&cost[v]>cost[u]+co){
				cost[v]=cost[u]+co;
				pre[v]=u;
				q.push(node{v,dis[v]});
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	init_graph();
	s++,t++;
	for(int i=1;i<=m;i++){
		int x,y,d,c;
		scanf("%d%d%d%d",&x,&y,&d,&c);
		x++,y++;
		addedge(x,y,d,c);
		addedge(y,x,d,c);
	}
	dij();
	vector<int> vec;
	for(int i=t;i;i=pre[i]){
		vec.push_back(i-1);
	}
	for(int i=vec.size()-1;i>=0;i--){
		printf("%d ",vec[i]);
	}
	printf("%lld %lld",dis[t],cost[t]);
	return 0;
}