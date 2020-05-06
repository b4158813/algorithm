#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
int n,m;
struct Edge{
	int u,v,w,next;
	bool f;
}e[5000005];
int cnt,head[5000005];
inline void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u],false};
	head[u]=cnt++;
}
stack<int> sta;
void dfs(int x){
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		if(e[i].f==false){
			e[i].f=true;
			dfs(v);
		}
	}
	printf("%d\n",x);
}
int main(){
	scanf("%d%d",&n,&m); 
	init();
	int u,v;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1);
	return 0;
}
