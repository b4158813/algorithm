#include<bits/stdc++.h>
using namespace std;
int n,k,ran[1005],fa[1005];
inline void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		ran[i]=1;
	}
}

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline void unite(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(ran[x]<ran[y]) {
		fa[x] = y;
	}else{
		fa[y]=x;
		if(ran[x]==ran[y]) ran[x]++;
	}
}

int main(){
	cin>>n>>k;
	init();
	for(int i=1;i<=k;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x==1){
			unite(y,z);
		}
		if(x==2){
			if(find(y)==find(z)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
	return 0;
}
