#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
const int inf=1<<30;
struct Edge{
	int u,v,w,next;
}e[10005];

int n,a,b,cnt,head[10005];
inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}
int vis[10005],dis[10005];
inline void spfa(int st){
	for(int i=1;i<=n;i++) dis[i]=inf;
	vis[st]=1;
	dis[st]=0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int y;
			scanf("%d",&y);
			if(j==1) addedge(i,y);
			else addedge(i,y,1);
		}
	}
	spfa(a);
	printf("%d\n",dis[b]==inf?-1:dis[b]);
	return 0;
}
