#include<cstring>
#include<cstdio>
using namespace std;
struct Edge{
	int v,next;
}e[500005];
int cnt,head[500005];
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++; 
}
int n,m,id,used[500005],have[500005],omg[500005];
bool Hungary(int u){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(used[v]!=id){
			used[v]=id;
			if(!have[v]||Hungary(have[v])){
				have[v]=u,omg[u]=v;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addedge(i,x+1),
		addedge(i,y+1);
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		id++;
		if(Hungary(i)) ans++;
		else break;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
		printf("%d\n",omg[i]-1);
	}
	return 0;
}
