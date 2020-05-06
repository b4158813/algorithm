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
int n,dp[6005][2],indeg[50005];

inline void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
	memset(dp,0,sizeof(dp));
	memset(indeg,0,sizeof(indeg));
}

void dfs(int x){
	dp[x][1]=1;
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		dfs(v);
		dp[x][0]+=dp[v][1];
		dp[x][1]+=min(dp[v][1],dp[v][0]);
	}
}

int main(){
	while(~scanf("%d",&n)){
		init();
		int u,k,x;
		for(int i=1;i<=n;i++){
			scanf("%d:(%d)",&u,&k);
			for(int j=1;j<=k;++j){
				scanf("%d",&x);
				addedge(u,x);
				indeg[x]++;
			}
		}
		int start;
		for(int i=0;i<n;i++){
			if(indeg[i]==0){
				start=i;
				break;
			}
		}
		dfs(start);
		printf("%d\n",min(dp[start][0],dp[start][1]));
	}
	return 0;
}
