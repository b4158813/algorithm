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
const int maxn=100005;
ll qpow(ll x,ll y) {ll ans=1,base=x; while(y){if(y&1)ans=(ans*base)%mod;base=(base*base)%mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
const int N=500005,M=500005;
struct Edge{
	int u,v,w,next;
}e[M<<1];
int n,k,cnt,head[N],tdiff[N];
inline void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
int vis[N],fa[N][21],dep[N],ans;
void lcadfs(int u){
	vis[u]=1;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!vis[v]){
			fa[v][0]=u;
			dep[v]=dep[u]+1;
			lcadfs(v);
		}
	}
}
void init_lca(){
	rep(i,1,20){
		rep(j,1,n){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
}
inline int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fa[x][int(log2(dep[x]-dep[y]))];
	if(x==y) return x;
	for(int i=log2(dep[x]);i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i],y=fa[y][i];
		}
	}
	return fa[x][0];
}
int dfs(int u,int fath){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			tdiff[u]+=dfs(v,u);
		}
	}
	ans=max(ans,tdiff[u]);
	return tdiff[u];
}
int main(){
	scanf("%d%d",&n,&k);
	init();
	int x,y;
	rep(i,1,n-1) scanf("%d%d",&x,&y),addedge(x,y),addedge(y,x);
	lcadfs(1);
	init_lca();
	rep(i,1,k){
		scanf("%d%d",&x,&y);
		int lca=LCA(x,y);
		tdiff[y]++;
		tdiff[x]++;
		tdiff[lca]--;
		tdiff[fa[lca][0]]--;
	}
	dfs(1,-1);
	printf("%d\n",ans);
	return 0;
}