#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(register int i=a;i<=b;i++)
const int maxn=100005;
int head[maxn<<1],cnt;
struct Edge
{
	int u,v,w,next;
}e[maxn<<1];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
int n,q,a[maxn],u,v,w,xorsum[maxn];

int dfsx,csid[maxn],csdep[maxn],cssize[maxn],csfa[maxn],csson[maxn],cstop[maxn];

// first dfs
inline void csdfs1(int u,int fath,int depth){
	csfa[u]=fath;
	csdep[u]=depth;
	cssize[u]=1;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			csdfs1(v,u,depth+1);
			cssize[u]+=cssize[v];
			if(cssize[v]>cssize[csson[u]])
				csson[u]=v;
		}
	}
}

//second dfs
inline void csdfs2(int u,int topf){
	csid[u]=++dfsx;
	cstop[u]=topf;
	if(!csson[u]) return;
	csdfs2(csson[u],topf);
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=csfa[u]&&v!=csson[u])
			csdfs2(v,v);
	}
}

/*--------------------------------------*/

// get LCA
inline int getLCA(int x,int y){
	while(cstop[x]!=cstop[y]){
		if(csdep[cstop[x]]<csdep[cstop[y]])
			swap(x,y);
		x=csfa[cstop[x]];
	}
	return csdep[x]<csdep[y]?x:y;
}

void dfs(int u,int fath){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			xorsum[v]=xorsum[u]^a[v];
			dfs(v,u);
		}
	}
}

inline void init_heavy_path(){
	csdfs1(1,-1,1);
	csdfs2(1,1);
	xorsum[1]=a[1];
	dfs(1,-1);
}


inline int getxorsum(int u,int v){
	return xorsum[u]^xorsum[v]^a[getLCA(u,v)];
}


int main(){
	// freopen("test.in","r",stdin);
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}

	init_heavy_path();

	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&u,&v);
		printf("%d\n",getxorsum(u,v));
		// printf("LCA=%d\n",getLCA(u,v));
	}
	return 0;
}