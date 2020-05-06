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
const int maxn=500005;
ll qpow(ll x,ll y) {ll ans=1,base=x; while(y){if(y&1)ans=(ans*base)%mod;base=(base*base)%mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

const int N=500005,M=2*500005;
struct Edge{
	int u,v,w,next;
}e1[M<<1],e2[M<<1];
int cnt1,head1[N],cnt2,head2[N];
int n,m,q;
int low[maxn],dfn[maxn],sta[maxn],vis[maxn],color[maxn],top,scc,deep;
int fa[maxn][21],dist[maxn][21],dep[maxn];
inline void init(){
	cnt1=cnt2=0;
	memset(head1,-1,sizeof(head1));
	memset(head2,-1,sizeof(head2));
}
inline void addedge1(int u,int v,int w=0){
	e1[cnt1]=Edge{u,v,w,head1[u]};
	head1[u]=cnt1++;
}
inline void addedge2(int u,int v,int w=0){
	e2[cnt2]=Edge{u,v,w,head2[u]};
	head2[u]=cnt2++;
}

inline void tarjan(int u,int fath){
	vis[sta[++top]=u]=1;
	low[u]=dfn[u]=++deep;
	for(int i=head1[u];~i;i=e1[i].next){
		int v=e1[i].v;
		if(v==fath) continue;
		// if(i==(fath^1)) continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		vis[u]=0;
		color[u]=++scc;
		while(sta[top]!=u){
			vis[sta[top]]=0;
			color[sta[top--]]=scc;
		}
		top--;
	}
}

inline void dfs(int u){
	vis[u]=1;
	for(int i=head2[u];~i;i=e2[i].next){
		int v=e2[i].v;
		if(!vis[v]){
			dep[v]=dep[u]+1;
			fa[v][0]=u;
			dist[v][0]=1;
			dfs(v);
		}
	}
}

inline int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int ans=0;
	while(dep[x]>dep[y]){
		ans+=dist[x][int(log2(dep[x]-dep[y]))];
		x=fa[x][int(log2(dep[x]-dep[y]))];
	}
	if(x==y) return ans;
	for(int i=log2(dep[x]);i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			ans+=dist[x][i]+dist[y][i];
			x=fa[x][i],y=fa[y][i];
		}
	}
	ans+=dist[x][0]+dist[y][0];
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	rep(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge1(u,v,1);
		addedge1(v,u,1);
	}

	rep(i,1,n) if(!dfn[i]) tarjan(i,-1);

	rep(u,1,n){
		for(int i=head1[u];~i;i=e1[i].next){
			int v=e1[i].v;
			if(color[u]!=color[v]){
				addedge2(color[u],color[v],1);
			}
		}
	}
	// rep(i,1,n) printf("%d scc:%d\n",i,color[i]);
	memset(vis,0,sizeof(vis));
	dfs(1);
	rep(i,1,20){
		rep(j,1,scc){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			dist[j][i]=dist[j][i-1]+dist[fa[j][i-1]][i-1];
		}
	}

	scanf("%d",&q);
	rep(i,1,q){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",LCA(color[x],color[y]));
	}
	return 0;
}
//https://www.acwing.com/problem/content/description/399