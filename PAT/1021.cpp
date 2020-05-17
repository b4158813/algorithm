#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int fa[maxn],vis[maxn];
int n,x,y;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}

struct Edge{
	int u,v,w,next;
}e[maxn<<1];
int gcnt,head[maxn];
inline void init_graph(){
	gcnt=0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int w=0){
	e[gcnt]=Edge{u,v,w,head[u]};
	head[u]=gcnt++;
}


set<int> se;
int rt=1,ans=0,top;
int dp[maxn];
void dfs(int u,int fath,int len){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			dfs(v,u,len+1);
			if(len+1>ans){
				ans=len+1;
				rt=v;
				se.clear();
				se.insert(v);
			}else if(len+1==ans){
				se.insert(v);
			}
		}
	}
}


int main(){
	scanf("%d",&n);
	init();
	init_graph();
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
		fa[find(x)]=find(y);
	}
	int an=0;
	for(int i=1;i<=n;i++){
		if(!vis[find(i)]) vis[find(i)]=1,an++;
	}
	if(an!=1){
		printf("Error: %d components\n",an);;
		return 0;
	}
	dfs(n,-1,0);
	top=rt;
	dfs(rt,-1,0);
	se.insert(top);
	for(auto t:se){
		printf("%d\n",t);
	}
	return 0;
}