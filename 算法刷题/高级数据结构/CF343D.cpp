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
#define ls i<<1
#define rs i<<1|1
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int,int> PII;
const db PI=acos(-1.0);
const db eps=1e-6;
const ll mod=1e9+7;
const int inf=2147483647;
const int maxn=500005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,q;

struct Edge{
	int u,v,w,next;
}e[maxn<<1];
int cnt,head[maxn];
inline void init_graph(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}

#define IT set<odtnode>::iterator
struct odtnode
{
	int l,r;
	mutable ll v;
	odtnode(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
	bool operator <(const odtnode& rhs)const{
		return l<rhs.l;
	}
};
set<odtnode> odt;

inline IT split(int pos){
	IT it=odt.lower_bound(odtnode(pos));
	if(it!=odt.end()&&it->l==pos) return it;
	it--;
	int l=it->l,r=it->r;
	ll v=it->v;
	odt.erase(it);
	odt.insert(odtnode(l,pos-1,v));
	return odt.insert(odtnode(pos,r,v)).first;
}

// Assign to same value
inline void assign(int l,int r,ll k){
	IT itr=split(r+1),itl=split(l);
	odt.erase(itl,itr);
	odt.insert(odtnode(l,r,k));
}

/*------------------------------------*/
/* Heavy Path Decomposition */
// dfs序、深度、子树大小、父节点、重儿子、链顶
int dfsx,csid[maxn],csdep[maxn],cssize[maxn],csfa[maxn],csson[maxn],cstop[maxn];
// value need to maintain
int csw[maxn];

// first dfs
inline void csdfs1(int u,int fath,int depth){
	csfa[u]=fath;
	csdep[u]=depth;
	cssize[u]=1;
	/* long path dec */
	// cssize[u]=csdep[u];
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			/* edge to point */
			// w[v]=e[i].w;
			// wdep[v]+=w[v];
			csdfs1(v,u,depth+1);
			cssize[u]+=cssize[v];
			/* long path dec */
			// cssize[u]=max(cssize[u],cssize[v]);
			if(cssize[v]>cssize[csson[u]])
				csson[u]=v;
		}
	}
}

//second dfs
inline void csdfs2(int u,int topf){
	csid[u]=++dfsx;
	/* value need to maintain */
	// csw[dfsx]=u;
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


inline void addrt(int x){
	assign(csid[x],csid[x]+cssize[x]-1,1);
}

inline void droprt(int x){
	int y=1;
	while(cstop[x]!=cstop[y]){
		if(csdep[cstop[x]]<csdep[cstop[y]])
			swap(x,y);
		assign(csid[cstop[x]],csid[x],0);
		x=csfa[cstop[x]];
	}
	if(csdep[x]>csdep[y]) swap(x,y);
	assign(csid[x],csid[y],0);
}

inline int isfull(int x){
	IT it=split(csid[x]);
	return it->v;
}


int main(){
	scanf("%d",&n);
	init_graph();
	int x,y;
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	csdfs1(1,-1,1);
	csdfs2(1,1);
	odt.insert(odtnode(1,n,0));
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		if(x==1) addrt(y);
		if(x==2) droprt(y);
		if(x==3) printf("%d\n",isfull(y));
	}
	return 0;
}