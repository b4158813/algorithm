#include<cstdio>
#include<cstring>
using namespace std;
struct Edge{
	int v,next;
}e[500005];
int n,m,ee,cnt,head[500005],used[500005],have[500005];
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
bool Hungary(int u){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!used[v]){
			used[v]=1;
			if(!have[v]||Hungary(have[v])){
				have[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		if(Hungary(i)) ans++;
	}
	printf("%d\n",ans/2);
//	for(int i=1;i<=n;i++){
//		printf("%d ",have[i]==0?0:have[i]-n);
//	}
	return 0;
}
