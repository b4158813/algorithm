#include<bits/stdc++.h>
using namespace std;
int n,m,id,k;
struct Edge
{
	int u,v,next;
}e[10005];
int cnt,head[10005];
inline void addedge(int u,int v){
	e[++cnt]=Edge{u,v,head[u]};
	head[u]=cnt;
}

int ans[10005];
int maxdepth;
void dfs(int u,int fath,int depth){
	maxdepth=max(maxdepth,depth);
	if(!head[u]) ans[depth]++;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			dfs(v,u,depth+1);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&id,&k);
		for(int j=1;j<=k;j++){
			int x;
			scanf("%d",&x);
			addedge(id,x);
		}
	}
	dfs(1,-1,1);
	for(int i=1;i<maxdepth;i++){
		printf("%d ",ans[i]);
	}
	printf("%d",ans[maxdepth]);
	return 0;
}