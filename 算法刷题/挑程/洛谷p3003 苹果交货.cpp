#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
struct Edge{
	int u,v,w,next;
}e[1000005];

struct node{
	int u,w;
	bool operator<(const node&rhs)const{
		return w>rhs.w;
	}
};

int cnt,dis1[1000005],dis2[1000005];
int head[5000005];
int pb,pa1,pa2,n,m,vis1[1000005],vis2[1000005];
inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dij1(){
	for(int i=1;i<=n;i++) dis1[i]=inf;
	priority_queue<node> q;
	dis1[pb]=0;
	q.push(node{pb,0});
	while(!q.empty()){
		node q1=q.top();
		q.pop();
		int u=q1.u,d=q1.w;
		if(d>dis1[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis1[v]>dis1[u]+w){
				dis1[v]=dis1[u]+w;
				q.push(node{v,dis1[v]});
			}
		}
	}
}

inline void dij2(){
	for(int i=1;i<=n;i++) dis2[i]=inf;
	priority_queue<node> q;
	dis2[pa1]=0;
	q.push(node{pa1,0});
	while(!q.empty()){
		node q1=q.top();
		q.pop();
		int u=q1.u,d=q1.w;
		if(d>dis2[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis2[v]>dis2[u]+w){
				dis2[v]=dis2[u]+w;
				q.push(node{v,dis2[v]});
			}
		}
	}
}

int main(){
	cin>>m>>n>>pb>>pa1>>pa2;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dij1();dij2();
	int ans=min(dis1[pa1]+dis2[pa2],dis1[pa2]+dis2[pa2]);
	cout<<ans<<endl;
	return 0;
}
