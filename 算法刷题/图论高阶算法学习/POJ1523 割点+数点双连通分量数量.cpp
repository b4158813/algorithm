#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
using namespace std;
struct Edge{
	int v,next;
}e[50005];

int cnt,head[2005];

inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}

int dfn[2005],low[2005],cut[2005],deep;

void tarjan(int u,int fa){
	low[u]=dfn[u]=++deep;
	int child=0;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v,fa);
			low[u]=min(low[u],low[v]);
			if(u!=fa&&low[v]>=dfn[u]) cut[u]=1;
			if(u==fa) child++;
		}
		low[u]=min(low[u],dfn[v]);
	}
	if(u==fa&&child>1) cut[u]=1;
}

int n,u,v,Cnt,ge[2005],color[2005];

inline void init(){
	n=Cnt=cnt=deep=0;
	memset(head,-1,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(cut,0,sizeof(cut));
	memset(ge,0,sizeof(ge));
}

void dfs(int x,int gg,int ID){
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=gg&&color[v]==-1){
			color[v]=ID;
			dfs(v,gg,ID);
		}
	}
}



int main(){
	ios::sync_with_stdio(false);
	init();
	int t=0;
	bool f=false;
	while(cin>>u){
		if(u==0&&f==false) break;
		f=true;
		if(u==0){
			++t;
			for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,i);
			Cnt=0;
			for(int i=1;i<=n;i++){
				if(cut[i]) ge[++Cnt]=i;
			}
			printf("Network #%d\n",t);
			if(Cnt==0) printf("  No SPF nodes\n\n");
			else{
				for(int g=1;g<=Cnt;g++){
					memset(color,-1,sizeof(color));
					int CNT=0;
					for(int i=1;i<=n;i++){
						if(i!=ge[g]&&color[i]==-1){
							++CNT;
							color[i]=CNT;
							dfs(i,ge[g],CNT);
						}
					}
					printf("  SPF node %d leaves %d subnets\n",ge[g],CNT);
				}
				printf("\n");
			}
			init();
			f=false;
			continue;
		}
		cin>>v;
		addedge(u,v);
		addedge(v,u);
		n=max(n,max(u,v));
	}
	return 0;
}
