#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
inline ll read() { 
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}

const int inf=1<<30;
struct Edge{
	int v,next;
}e[500005];
int cnt,head[50005];
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
int n,dp[500005][3];

inline void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
bool vis[500005];

void dfs(int x,int fa){
	dp[x][0]=1;
	bool f=false;
	int minh=inf;
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,x);
		dp[x][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
		dp[x][1]+=min(dp[v][0],dp[v][2]);
		if(dp[v][0]<=dp[v][2]){
			f=true;
			dp[x][2]+=dp[v][0];
		}else{
			minh=min(minh,dp[v][0]-dp[v][2]);
			dp[x][2]+=dp[v][2];
		}
	}
	
	if(!f){
		dp[x][2]+=minh;
	}
}
int main(){
	n=read();
	init();
	int u,v;
	for(int i=1;i<n;i++){
		u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,-1);
	printf("%d\n",min(dp[1][0],dp[1][2]));
	return 0;
}
