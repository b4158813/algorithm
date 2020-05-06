#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int inf=1e8;
int n,m;
int cnt,head[30005],dis[30005];
struct Edge{
	int u,v,w,next;
}e[150005];

struct node{
	int u,dis;
	bool operator<(const node &rhs)const{
		return dis>rhs.dis;
	}
};
inline void addedge(int u,int v,int w){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline void spfa(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	priority_queue<node> q;
	q.push(node{1,0});
	dis[1]=0;
	while(!q.empty()){
		node q1=q.top();q.pop();
		int u=q1.u;
		if(q1.dis>dis[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(node{v,dis[v]});
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	spfa();
	printf("%d\n",dis[n]);
	return 0;
}
