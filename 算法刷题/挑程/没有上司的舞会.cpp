#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const double inf=1ll<<60;

struct Edge{
	int u,v,w,next;
}e[100005];
int n,cnt,val[10005];
int f[10005],g[10005],head[10005],indeg[10005];
inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

void dfs(int x){
	f[x]=val[x];
	for(int i=head[x];i;i=e[i].next){
		dfs(e[i].v);
		f[x]+=g[e[i].v];
		g[x]+=max(f[e[i].v],g[e[i].v]);
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>val[i];
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		addedge(v,u);
		indeg[u]++;
	}
	int root;
	for(int i=1;i<=n;i++)
		if(indeg[i]==0){
			root=i;
			break;
		}
			
	dfs(root);
	cout<<max(f[root],g[root])<<endl;
	return 0;
}


