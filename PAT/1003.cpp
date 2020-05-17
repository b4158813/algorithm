#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
const int inf=1<<30;
#define rep(i,a,b) for(register int i=a;i<=b;i++)
const int maxn=200005;
struct Edge
{
	int u,v,w,next;
}e[maxn<<1];

struct node
{
	int v,dis;
	bool operator<(const node& rhs)const{
		return dis>rhs.dis;
	}
};
int cnt,head[maxn];
inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}
int n,m,c1,c2,vis[maxn],ww[maxn];
int dis[maxn];
int ans1[maxn],pp[maxn],ans2[maxn],pre[maxn];
inline void spfa(){
	rep(i,1,n) dis[i]=inf;
	priority_queue<node> q;
	q.push(node{c1,0});
	dis[c1]=0;
	ans1[c1]=1;
	ans2[c1]=ww[c1];
	while(q.size()){
		node q1=q.top();
		q.pop();
		int u=q1.v;
		if(q1.dis>dis[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				// printf("ahhh:%d\n",v);
				dis[v]=dis[u]+w;
				ans1[v]=ans1[u];
				ans2[v]=ans2[u]+ww[v];
				q.push(node{v,dis[v]});
			}else if(dis[v]==dis[u]+w){
				ans1[v]+=ans1[u];
				ans2[v]=max(ans2[v],ans2[u]+ww[v]);
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	c1++,c2++;
	rep(i,1,n) scanf("%d",&ww[i]);
	int u,v,z;
	rep(i,1,m){
		scanf("%d%d%d",&u,&v,&z);
		u++,v++;
		addedge(u,v,z),addedge(v,u,z);
	}
	spfa();
	printf("%d %d",ans1[c2],ans2[c2]);
}