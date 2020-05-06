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
int n,dp[60005][2],Size[50005],ans[50005];

inline void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
bool giao[10005],f;
void dfs(int x,int fa){
	Size[x]=1;
	ans[x]=0;
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,x);
		Size[x]+=Size[v];
		ans[x]=max(ans[x],Size[v]);
	}
	if(ans[x]<=n/2&&n-Size[x]<=n/2){
		giao[x]=1;
	}
}

int main(){
	scanf("%d",&n);
	init();
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u); 
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		if(giao[i]){
			f=true;
			printf("%d\n",i);
		}
	}
	if(!f) printf("NONE\n");
	return 0;
}
