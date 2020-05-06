#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=2147483647;

struct Edge{
	int u,v,w,next;
}e[1000005];

int n,m,s,ans,cnt,vis[1000005],head[1000005];
inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int dis[1000005];
inline void SPFA(){
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	}
	queue<int> q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	SPFA();
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}
