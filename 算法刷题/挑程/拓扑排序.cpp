#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,next;
}e[100005];

int n,m,cnt,head[100005],indeg[100005];
inline void addedge(int u,int v){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int ans[100005],ccnt;
inline void topo_sort(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans[++ccnt]=u;
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
		addedge(u,v);
		indeg[v]++;
	}
	topo_sort();
	for(int i=1;i<=ccnt;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
