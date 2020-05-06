#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn=6006;
const int mod=1e9+7;
int n,hap[maxn];
const int N=500005,M=500005;
struct Edge{
	int u,v,w,next;
}e[M];
int cnt,head[N];
int dp[maxn][2],deg[maxn];
inline void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
void dfs(int u,int fa){
	dp[u][1]=hap[u];
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		dp[u][1]+=dp[v][0];
		dp[u][0]+=max(dp[v][1],dp[v][0]);
	}
}

int main() {
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++){
    	scanf("%d",&hap[i]);
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
		deg[y]++;
	}
	
	dfs(1,-1);
	printf("%d\n",max(dp[1][0],dp[1][1]));
    return 0;
}

