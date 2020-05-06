#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Edge{
	int u,v,w,next;
	bool f;
}e[50005];
int cnt,head[50005];
void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u],false};
	head[u]=cnt++;
}
stack<int> sta;
void dfs(int u){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!e[i].f){
			e[i].f=e[i^1].f=1;
			dfs(v);
		}
	}
	sta.push(u);
}
int main(){
	cin>>n>>m;
	int u,v;init();
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	
	dfs(1);
	while(sta.size()){
		cout<<sta.top()<<" ";
		sta.pop(); 
	}
	return 0;
}
