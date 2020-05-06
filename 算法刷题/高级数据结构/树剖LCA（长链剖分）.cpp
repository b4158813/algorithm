#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int maxn=1000005;

inline ll read() {//快读
	ll kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}

inline void write(ll x){//快写
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}

struct Edge
{
	int u,v,w,next;
}e[maxn<<1];
int cnt,head[maxn];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
inline void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
int n,m,r,x,y;
int dfsx,csdep[maxn],csid[maxn],csfa[maxn],csson[maxn],cstop[maxn],csmx[maxn];


// 第一次dfs：处理出 深度、父亲、子树大小、重儿子
inline void dfs1(int u,int fath,int depth){
	csdep[u]=depth;
	csfa[u]=fath;
	csmx[u]=csdep[u];
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			dfs1(v,u,depth+1);
			csmx[u]=max(csmx[v],csmx[u]);
			if(csmx[v]>csmx[csson[u]])
				csson[u]=v;
		}
	}
}

// 第二次dfs：求出dfs序、dfs序对应初始值、节点所在链的顶端
inline void dfs2(int u,int topf){
	csid[u]=++dfsx;
	cstop[u]=topf;
	if(!csson[u]) return;
	dfs2(csson[u],topf);
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=csfa[u]&&v!=csson[u]){
			dfs2(v,v);
		}
	}
}

inline int LCA(int x,int y){
	while(cstop[x]!=cstop[y]){
		if(csdep[cstop[x]]<csdep[cstop[y]]) swap(x,y);
		x=csfa[cstop[x]];
	}
	return csdep[x]<csdep[y]?x:y;
}

int main(){
	n=read(),m=read(),r=read();
	init();
	rep(i,1,n-1){
		x=read(),y=read();
		addedge(x,y);
		addedge(y,x);
	}
	dfs1(r,-1,1);
	dfs2(r,r);
	rep(i,1,m){
		x=read(),y=read();
		write(LCA(x,y)),putchar('\n');
	}
	return 0;
}