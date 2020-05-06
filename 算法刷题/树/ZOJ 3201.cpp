#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct Edge{
	int v,next;
}e[50005];
int cnt,head[505];
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
int n,k,val[505],dp[205][205];

inline void init(){
	cnt=0;
	memset(dp,0,sizeof(dp));
	memset(val,0,sizeof(val));
	memset(head,-1,sizeof(head));
}

void dfs(int x,int fa){
	dp[x][1]=val[x];
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,x);
		for(int j=k;j>=1;j--){
			for(int l=j-1;l>=1;l--){
				dp[x][j]=max(dp[x][j],dp[x][j-l]+dp[v][l]);
			}
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&k)){
		init();
		int u,v;
		for(int i=0;i<n;i++){
			scanf("%d",&val[i]);
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		
		dfs(0,-1);
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,dp[i][k]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
