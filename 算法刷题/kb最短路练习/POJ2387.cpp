#include<iostream>
#include<algorithm>
#include<queue> 
using namespace std;
typedef long long ll;
const int inf = 2147483647;
struct Edge{
	int u,v,w,next;
}e[1000005];

struct node{
	int u,dis;
	bool operator <(const node&rhs)const{
		return dis>rhs.dis;
	}
};

int n,m,s,ans,cnt,now,head[1000005],dis[1000005];
inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dijkstra(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	priority_queue<node> q;
	dis[n]=0;
	q.push((node){n,0});
	while(!q.empty()){
		node q1=q.top();
		q.pop();
		int u=q1.u;
		if(q1.dis>dis[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push((node){v,dis[v]});
			}
		}
	}
}

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dijkstra();
	cout<<dis[1]<<endl;
	return 0;
}
