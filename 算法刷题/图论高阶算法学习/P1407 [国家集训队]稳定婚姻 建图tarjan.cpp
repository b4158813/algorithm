#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
struct Edge{
	int v,next;	
}e[80005];
int n,m,cnt,ccnt,head[40005];
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
int deep,num,top,low[40005],dfn[40005],color[40005],sta[40005],vis[40005];
void tarjan(int u){
	vis[sta[++top]=u]=1;
	dfn[u]=low[u]=++deep;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
//		if(v==fa) continue;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		vis[u]=0;
		color[u]=++num;
		while(sta[top]!=u){
			vis[sta[top]]=0;
			color[sta[top--]]=num;
		}
		top--;
	}
}
int main(){
	string s1,s2;
	map<string,int> ma;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		ma[s1]=++ccnt;
		ma[s2]=++ccnt;
		addedge(ma[s1],ma[s2]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		cin>>s1>>s2;
		addedge(ma[s2],ma[s1]);
	}
	for(int i=1;i<=2*n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=2*n;i+=2){
		if(color[i]!=color[i+1]){
			printf("Safe\n");
		}else printf("Unsafe\n");
	}
	return 0;
}
