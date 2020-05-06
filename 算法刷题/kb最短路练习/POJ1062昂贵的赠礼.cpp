#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf=1<<30;
struct Edge{
	int u,v,w,next;
}e[10005];
int n,m,cnt=0,head[10005],sta[10005],vis[10005];
int dis[10005];
inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline int spfa(int low,int high){
	memset(dis,0x3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	vis[0]=1;
	q.push(0);
	dis[0]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(sta[v]<low||sta[v]>high) continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[1];
}

int main(){
	scanf("%d%d",&m,&n);
	int p,l,x,t,v;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&p,&l,&x);
		addedge(0,i,p);
		sta[i]=l;
		for(int j=1;j<=x;++j){
			scanf("%d%d",&t,&v);
			addedge(t,i,v);
		}
	}
	int ans=inf;
	for(int i=sta[1]-m;i<=sta[1];++i){
		ans=min(ans,spfa(i,i+m));
	}
	printf("%d\n",ans);
	return 0;
}
