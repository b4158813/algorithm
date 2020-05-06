#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int maxm = 200005;
const int inf = 1<<30;
struct node{
	int u,v,w,next;
}e[2*maxm];
int n,m,cnt=0;
int head[maxn];
inline void addedge(int u,int v,int w){
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

inline void init(){
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		addedge(x,y,z);
		addedge(y,x,z);
	}
}
int vis[maxn],dis[maxn],tot,now=1,ans;
inline void prim(){
	for(int i=2;i<=n;i++){
		dis[i]=inf;
	}
	for(int i=head[1];i;i=e[i].next){
		dis[e[i].v] = min(dis[e[i].v],e[i].w);
	}
	while(++tot<n){
		int minh=inf;
		vis[now]=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&minh>dis[i]){
				now=i;
				minh=dis[i];
			}
		}
		ans+=minh;
		for(int i=head[now];i;i=e[i].next){
			int v = e[i].v;
			if(!vis[v]&&e[i].w<dis[v]){
				dis[v]=e[i].w;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	init();
	prim();
	cout<<ans<<endl;
	return 0;
}
