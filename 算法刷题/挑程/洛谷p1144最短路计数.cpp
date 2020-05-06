#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
struct Edge{
	int u,v,w,next;
}e[4000005];
int n,m,cnt,head[4000005];
inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int ans[10000005],dis[1000005],vis[1000005];
inline void spfa(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	queue<int> q;
	vis[1]=1;
	dis[1]=0;
	ans[1]=1;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				ans[v]=ans[u];
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}else if(dis[v]==dis[u]+w){
				ans[v] = (ans[v]+ans[u])%100003;
			} 
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y) continue;
		addedge(x,y,1);
		addedge(y,x,1);
	}
	spfa();
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}
