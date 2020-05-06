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

int n,m,q,Fa[maxn],fa[maxn][21],w[maxn][21],dep[maxn],cnt1,cnt2,head1[maxn],head2[maxn];
bool vis[maxn];
inline int find(int x){return x==Fa[x]?x:Fa[x]=find(Fa[x]);}
struct Edge
{
	int u,v,w,next;
}e1[maxn<<1],e2[maxn<<1];
bool cmp(Edge x1,Edge x2){
	return x1.w>x2.w;
}
inline void addedge1(int u,int v,int w=0){
	e1[++cnt1]=Edge{u,v,w,head1[u]};
	head1[u]=cnt1;
}
inline void addedge2(int u,int v,int w=0){
	e2[++cnt2]=Edge{u,v,w,head2[u]};
	head2[u]=cnt2;
}
inline void init(){
	rep(i,1,n) Fa[i]=i;
	cnt1=cnt2=0;
}
inline void dfs(int u){
	for(int i=head2[u];i;i=e2[i].next){
		int v=e2[i].v;
		if(!vis[v]){
			vis[v]=1;
			dep[v]=dep[u]+1;
			fa[v][0]=u;
			w[v][0]=e2[i].w;
			dfs(v);
		}
	}
}

inline int LCAmin(int x,int y){
	if(find(x)!=find(y)) return -1;
	int ans=inf;
	if(dep[x]<dep[y]) x^=y^=x^=y;
	while(dep[x]>dep[y]){
		ans=min(ans,w[x][int(log2(dep[x]-dep[y]))]);
		x=fa[x][int(log2(dep[x]-dep[y]))];
	}
	if(x==y) return ans;
	for(int i=log2(dep[x]);i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			ans=min(ans,min(w[x][i],w[y][i]));
			x=fa[x][i],y=fa[y][i];
		}
	}
	return min(ans,min(w[x][0],w[y][0]));
}

inline void kruskal(){
	init();
	sort(e1+1,e1+1+m,cmp);
	for(int i=1;i<=m;i++){
		int eu=find(e1[i].u),ev=find(e1[i].v);
		if(eu!=ev){
			Fa[eu]=ev;
			addedge2(e1[i].u,e1[i].v,e1[i].w);
			addedge2(e1[i].v,e1[i].u,e1[i].w);
		}
	}
}
int main(){
	// freopen("P1967_1.in","r",stdin);
	scanf("%d%d",&n,&m);
	int x,y,z;
	rep(i,1,m){
		scanf("%d%d%d",&x,&y,&z);
		addedge1(x,y,z);
	}
	kruskal();
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i);
		}
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			w[j][i]=min(w[j][i-1],w[fa[j][i-1]][i-1]);
		}
	}
	scanf("%d",&q);
	rep(i,1,q){
		scanf("%d%d",&x,&y);
		printf("%d\n",LCAmin(x,y));
	}
	return 0;
}