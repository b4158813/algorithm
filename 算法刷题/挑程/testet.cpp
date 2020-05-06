#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int u,v,w,next;
}e[1000005];

int n,m,cnt,now=1,vis[100005],head[100005],dis[100005],tot,ans;
inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void prim(){
	for(int i=2;i<=n;i++){
		dis[i]=1<<30;
	}
	for(int i=head[1];i;i=e[i].next){
		dis[e[i].v]=min(dis[e[i].v],e[i].w);
	}
	while(++tot<n){
		int minh=1<<30;
		vis[now]=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<minh){
				minh=dis[i];
				now=i;
			}
		}
		ans+=minh;
		for(int i=head[now];i;i=e[i].next){
			int v=e[i].v;
			if(!vis[v]&&dis[v]>e[i].w){
				dis[v]=e[i].w;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	prim();
	cout<<ans<<endl;
	return 0;
}
