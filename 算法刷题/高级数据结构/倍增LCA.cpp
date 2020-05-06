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

int n,m,s,fa[maxn][21],dep[maxn],cnt,head[maxn];
bool vis[maxn];
struct Edge
{
	int u,v,w,next;
}e[maxn<<1];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
inline void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}
inline void dfs(int u){
	vis[u]=1;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!vis[v]){
			fa[v][0]=u;
			dep[v]=dep[u]+1;
			dfs(v);
		}
	}
}

inline int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){
		x=fa[x][int(log2(dep[x]-dep[y]))];
	}
	if(x==y) return x;
	for(int i=log2(dep[x]);i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i],y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	n=read(),m=read(),s=read();
	init();
	int x,y;
	rep(i,1,n-1){
		x=read(),y=read();
		addedge(x,y);
		addedge(y,x);
	}
	dfs(s);
	rep(i,1,20){
		rep(j,1,n){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	rep(i,1,m){
		x=read(),y=read();
		write(LCA(x,y)),putchar('\n');
	}
	return 0;
}