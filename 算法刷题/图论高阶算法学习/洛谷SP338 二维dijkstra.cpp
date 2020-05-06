#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int inf=1<<30;

struct Edge{
	int u,v,w,c,next;
}e[100005];
struct node{
	int u,dis,co;
	bool operator<(const node &rhs)const {
		return dis>rhs.dis;
	}
};
int n,m,k,cnt,head[10005],u,v,w,c,ans;
inline void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}
inline void addedge(int u,int v,int w,int c){
	e[cnt]=Edge{u,v,w,c,head[u]};
	head[u]=cnt++;
}
inline void dij(int st){
	priority_queue<node> q;
	q.push(node{st,0,0});
	while(!q.empty()){
		node q1=q.top();q.pop();
		int u=q1.u,d=q1.dis,co=q1.co;
		if(u==n){
			ans=d;
			return;
		}
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v,w=e[i].w,c=e[i].c;
			if(c+co<=k){
				q.push(node{v,d+w,c+co});
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ans=-1;
		init();
		scanf("%d%d%d",&k,&n,&m);
		for(int i=1;i<=m;++i){
			scanf("%d%d%d%d",&u,&v,&w,&c);
			addedge(u,v,w,c);
		}
		dij(1);
		printf("%d\n",ans);
	}
	return 0;
}
