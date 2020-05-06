#include<bits/stdc++.h>
using namespace std;
int t,n,sch[150],ghome[150],id,used[150],have[150];
struct Edge{
	int u,v,next;
}e[50005];
int cnt,head[50005];
inline void addedge(int u,int v){
	e[cnt]=Edge{u,v,head[u]};
	head[u]=cnt++;
}
inline void init(){
	memset(head,-1,sizeof(head));
	memset(sch,0,sizeof(sch));
	memset(ghome,0,sizeof(ghome));
	memset(have,0,sizeof(have));
	memset(used,0,sizeof(used));
	id=cnt=0;
}
bool Hungary(int u){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(used[v]!=id){
			used[v]=id;
			if(!have[v]||Hungary(have[v])){
				have[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main(){
//	freopen("input.in","r",stdin);
//	freopen("output,out","w",stdout);
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		int x,tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&sch[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&ghome[i]);
			if(sch[i]&&!ghome[i])
				addedge(i,i);
		}
		for(int i=1;i<=n;i++){
			if(!sch[i]||(sch[i]&&!ghome[i])) tot++;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&x);
				if(x==1){
					if(sch[j]){
						addedge(i,j);
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if((sch[i]&&!ghome[i])||!sch[i]){
				id++;
				if(Hungary(i)) ans++;
			}
		}
		if(ans==tot) printf("^_^\n");
		else printf("T_T\n");
	}
	return 0;
}
