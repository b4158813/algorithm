#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int val[100005],fa[100005],n,m,q;
inline void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
inline int find(int x){
	if(x!=fa[x]){
		int t=fa[x];
		fa[x]=find(fa[x]);
		val[x]+=val[t];
	}
	return fa[x];
}
inline void unite(int x,int y,int value){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		val[fx]=val[y]+value-val[x];
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	init();
	int x,y,z;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		unite(x,y,z);
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d",&x,&y);
		if(find(x)!=find(y)){
			printf("-1\n");
		}else{
			printf("%d\n",val[x]-val[y]);
		}
	}
	return 0;
} //https://vjudge.net/problem/HihoCoder-1515
