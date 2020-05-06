#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
struct Edge{
	int u,v,next;
	double R,C;
}e[1005];
int n,m,st,cnt,head[1005],vis[1005],ring[1005];
double dis[1005];
double sm;
inline void addedge(int u,int v,double R,double C){
	e[++cnt]=Edge{u,v,head[u],R,C};
	head[u]=cnt;
}
inline bool spfa(){
	memset(dis,0,sizeof(dis));
	vis[st]=1;
	dis[st]=sm;
	queue<int> q;
	q.push(st);
	ring[st]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			double R=e[i].R,C=e[i].C;
			if((dis[u]-C)*R>dis[v]){
				dis[v]=(dis[u]-C)*R;
				ring[v]=ring[u]+1;
				if(ring[v]>n) return true;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				} 
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d%d%lf",&n,&m,&st,&sm);
	int x1,x2;
	double rab,cab,rba,cba;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lf%lf%lf%lf",&x1,&x2,&rab,&cab,&rba,&cba);
		addedge(x1,x2,rab,cab);
		addedge(x2,x1,rba,cba);
	}
	if(spfa()) printf("YES\n");
	else printf("NO\n");
	return 0;
} //https://vjudge.net/problem/POJ-1860#author=0
