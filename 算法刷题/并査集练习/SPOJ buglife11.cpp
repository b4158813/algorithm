#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int val[2005],fa[2005],n,m,t;

inline void init(){
	memset(val,0,sizeof(val));
	for(int i=1;i<=n;i++) fa[i]=i;
}
inline int find(int x){
	if(x!=fa[x]){
		int t=fa[x];
		fa[x]=find(fa[x]);
		val[x]=(val[x]+val[t])%2;
	}
	return fa[x];
}

int main(){
	scanf("%d",&t);
	for(int o=1;o<=t;++o){
		bool f=true;
		scanf("%d%d",&n,&m);
		init();
		int x,y;
		for(int i=1;i<=m;++i){
			scanf("%d%d",&x,&y);
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				fa[fx]=fy;
				val[fx]=(val[y]+1-val[x]+2)%2;
			}else{
				if((val[x]-val[y]+2)%2==0){
					f=false;
				}
			}
		}
		printf("Scenario #%d:\n",o);
		if(f) printf("No suspicious bugs found!\n");
		else printf("Suspicious bugs found!\n");
	}
	return 0;
}

