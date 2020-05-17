#include<bits/stdc++.h>
using namespace std;
int a[5000005][2],vis[2000005];
int n,m,k,fa[2000005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
	memset(vis,0,sizeof(vis));
}



int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	while(k--){
		init();
		int x;;
		scanf("%d",&x);
		for(int i=1;i<=n;i++){
			if(a[i][0]==x||a[i][1]==x) continue;
			else{
				fa[find(a[i][0])]=find(a[i][1]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i==x) continue;
			if(!vis[find(i)]){
				vis[find(i)]=1;
				ans++;
			}
		}
		printf("%d\n",ans-1);
	}
	return 0;
}