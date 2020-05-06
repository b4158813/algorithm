#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=2147483647;

struct Edge{
	int u,v,w,next;
}e[3005];

int n,m,cnt,vis[2005],head[200005],ring[2005];
inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int dis[2005];
inline bool SPFA(){
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	}
	queue<int> q;
	q.push(1);
	dis[1]=0;
	vis[1]=1;
	ring[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(vis[v]==0){
					ring[v]=ring[u]+1;
					if(ring[v]>n) return true;
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cnt=0;
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(head));
		memset(ring,0,sizeof(ring));
		memset(dis,0,sizeof(dis));
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			addedge(u,v,w);
			if(w>=0) addedge(v,u,w);
		}
		if(SPFA()) cout<<"YE5"<<endl;
		else cout<<"N0"<<endl;
	}
	return 0;
}
