#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
}e[3000005];

bool cmp(Edge x1,Edge x2){
	return x1.w<x2.w;
}

int n,m,fa[1000005],ans,anss,cnt;

inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
}

inline void init(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline void unite(int x,int y){
	fa[find(x)]=find(y);
}

int ccc;
inline void kruskal(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int eu=e[i].u,ev=e[i].v;
		if(find(eu)==find(ev)) continue;
		anss=max(anss,e[i].w);
		ans++;
		unite(eu,ev);
	//	if(++ccc==n-1) break;
	}
}

int main(){
	cin>>n>>m;
	init(n);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	kruskal();
	cout<<ans<<" "<<anss;
	return 0;
}
