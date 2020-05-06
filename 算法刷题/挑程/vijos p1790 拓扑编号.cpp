#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int u,v,next;
}e[1000005];
int n,m,cnt,head[1000005],indeg[1000005];
inline void addedge(int u,int v){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int ans[1000005];
inline void tpsort(){
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			q.push(i);
		}
	}
	int num=n;
	while(!q.empty()){
		int u=q.top();
		q.pop();
		ans[u]=num--;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			if(indeg[v]){
				indeg[v]--;
				if(indeg[v]==0){
					q.push(v);
				}
			}
		}
	}
	
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		addedge(v,u);
		indeg[u]++;
	}
	tpsort();
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
	
} //https://vijos.org/p/1790
