#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define All(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int,int> PII;
const db PI=acos(-1.0);
const db eps=1e-6;
const ll mod=1e9+7;
const int inf=2147483647;
const int maxn=300005;
ll qpow(ll x,ll y) {ll ans=1,base=x; while(y){if(y&1)ans=(ans*base)%mod;base=(base*base)%mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
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

int n,m,head[maxn],cnt;
int longest,dfscnt,treediff[maxn],sta[maxn],top;
struct Edge
{
	int u,v,w,next;
}e[maxn<<1];
struct Q
{
	int u,v,lca,routesum;
}q[maxn];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}

int dfsx,csdep[maxn],csid[maxn],csfa[maxn],csson[maxn],cstop[maxn],cssize[maxn];
int wdep[maxn],w[maxn];

// 第一次dfs：处理出 深度、父亲、子树大小、重儿子
inline void dfs1(int u,int fath,int depth){
	csdep[u]=depth;
	csfa[u]=fath;
	cssize[u]=1;
	int maxsize=-1;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			wdep[v]=wdep[u]+e[i].w;
			w[v]=e[i].w;
			dfs1(v,u,depth+1);
			cssize[u]+=cssize[v];
			if(cssize[v]>maxsize)
				maxsize=cssize[v],csson[u]=v;
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

inline int getdist(int x,int y){
	return wdep[x]+wdep[y]-2*wdep[LCA(x,y)];
}


inline int DFS(int u,int fath){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			treediff[u]+=DFS(v,u);
		}
	}
	if(treediff[u]==dfscnt){
		sta[++top]=w[u];
	}
	return treediff[u];
}

inline bool check(int x){
	memset(treediff,0,sizeof(treediff));
	int maxh=0;
	dfscnt=0;
	rep(i,1,m){
		if(q[i].routesum>x){
			dfscnt++;
			treediff[q[i].u]++;
			treediff[q[i].v]++;
			treediff[q[i].lca]-=2;
		}
	}
	DFS(1,-1);
	while(top){
		maxh=max(maxh,sta[top--]);
	}
	return longest-maxh>x;
}

int main(){
	// freopen("P2680_13.in","r",stdin);
	n=read(),m=read();
	memset(head,-1,sizeof(head));
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dfs1(1,-1,1);
	dfs2(1,1);

	rep(i,1,m){
		q[i].u=read(),q[i].v=read();
		q[i].lca=LCA(q[i].u,q[i].v);
		q[i].routesum=getdist(q[i].u,q[i].v);
		longest=max(longest,q[i].routesum);
	}

	int l=0,r=longest;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	write(l),putchar('\n');
	return 0;
}