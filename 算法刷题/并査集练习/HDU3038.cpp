#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,fa[200005],val[200005];

inline void init(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
	}
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
		val[fx]=value+val[y]-val[x];
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(val,0,sizeof(val));
		int ans=0;
		init();
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			--x;
			int fx=find(x);
			int fy=find(y);
			if(fx==fy){
				if(val[x]-val[y]!=z){
					ans++;
				}
			}else{
				unite(x,y,z);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}