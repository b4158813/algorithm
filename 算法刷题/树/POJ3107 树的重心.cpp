#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f;
int cnt,head[500005];
struct Edge{
	int u,v,w,next;
}e[500005];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
int n,Size[500005],Ans=inf;
int ans[500005],ccnt;
void dfs(int x,int fa){
	Size[x]=1;
	ans[x]=0;
	for(int i=head[x];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fa){
			dfs(v,x);
			Size[x]+=Size[v];
			ans[x]=max(ans[x],Size[v]);
		}
	}
	ans[x]=max(ans[x],n-Size[x]);
	if(ans[x]<Ans){
		Ans=ans[x];
	}
}

int main(){
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		if(ans[i]==Ans) printf("%d ",i);
	}
	return 0;
}

