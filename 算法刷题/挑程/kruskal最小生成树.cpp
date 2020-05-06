#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int u,v,w,next; 
}e[200005];

bool cmp(Edge x1,Edge x2){
	return x1.w<x2.w;
}
int n,m,cnt,head[200005],fa[200005],ran[20005],ans;
inline void addedge(int u,int v,int w){
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

inline void unite(int x,int y){
	if(ran[x]>ran[y]){
		fa[y]=x;
	}else{
		fa[x]=y;
		if(ran[x]==ran[y]) ran[x]++;
	}
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		ran[i]=1;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
}

inline void kruskal(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int eu=find(e[i].u),ev=find(e[i].v);
		if(eu==ev) continue;
		ans+=e[i].w;
		unite(eu,ev);
	}
}

int main(){
	cin>>n>>m;
	init();
	kruskal();
	cout<<ans<<endl;
	return 0;
}
