#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct Edge{
	int v,next;
}e[50005];
int cnt,head[50005]; 
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
int n,indeg[6005],val[6005],dp[6005][2];

void dfs(int x){
	dp[x][1]=val[x];
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		dfs(v);
		dp[x][1]+=dp[v][0];
		dp[x][0]+=max(dp[v][0],dp[v][1]);
	}
}
int main(){
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	int u,v;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&u,&v);
		if(u==0&&v==0) break;
		addedge(v,u);
		indeg[u]++;
	}
	int start;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			start=i;
			break;
		}
	}
	dfs(start);
	printf("%d\n",max(dp[start][0],dp[start][1]));
	return 0;
}
