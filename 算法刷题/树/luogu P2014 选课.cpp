#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
	int u,v,w,next;
}e[5005];
int n,m,val[5005],cnt,head[5005],dp[305][5005];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}

void dfs(int x){
	dp[x][1]=val[x];
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		dfs(v);
		for(int j=m;j>=1;j--){
			for(int k=j-1;k>=1;k--){
				dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[v][k]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	++m;
	memset(head,-1,sizeof(head));
	int u;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&u,&val[i]);
		addedge(u,i);
	}
	dfs(0);
	printf("%d\n",dp[0][m]);
	return 0;
}
