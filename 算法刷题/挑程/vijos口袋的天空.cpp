#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w,next;
}e[3000005];

bool cmp(Edge x1,Edge x2){
	return x1.w<x2.w;
}

int n,m,k,fa[1000005],ans,anss,cnt,head[1000005];

inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
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
int ccnt,f[200005];
inline void kruskal(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int eu=e[i].u,ev=e[i].v;
		if(find(eu)==find(ev)) continue;
		unite(eu,ev);
		anss+=e[i].w;
		f[++ccnt]=e[i].w;
	}
}
set<int> se;
int main(){
	cin>>n>>m>>k;
	init(n);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	kruskal();
	int bc=0;
	for(int i=1;i<=n;i++){
		if(se.count(find(i))==0){
			se.insert(find(i));
			bc++;
		}
	}
	if(k<bc){
		cout<<"No Answer"<<endl;
		return 0;
	}else{
		int num=k-bc;
		while(num--){
			anss-=f[ccnt];
			ccnt--;
		}
		cout<<anss<<endl;
	}
	return 0;
}

