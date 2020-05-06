#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,e;
}a[1000005];

bool cmp(node x1,node x2){
	return x1.e>x2.e;
}

int fa[1000005],b[5000005];
set<int> se; 

inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline void unite(int x,int y){
	fa[find(x)]=find(y);
}

inline void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		bool f=true;
		int m;
		cin>>m;
		int tot=0;
		for(int i=1;i<=m;i++){
			cin>>a[i].x>>a[i].y>>a[i].e;
			b[++tot]=a[i].x;
			b[++tot]=a[i].y;
		}
		sort(b+1,b+tot+1);
		int unq = unique(b+1,b+tot+1)-b-1;
		for(int i=1;i<=m;i++){
			a[i].x = lower_bound(b+1,b+1+unq,a[i].x)-b;
			a[i].y = lower_bound(b+1,b+1+unq,a[i].y)-b;
		}
		init(unq);
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(a[i].e==1) unite(a[i].x,a[i].y);
			else{
				if(find(a[i].x)==find(a[i].y)){
					f=false;
					break;
				}
			}
		}
		if(f) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
