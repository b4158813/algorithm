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
const double PI=acos(-1.0);
const double eps=1e-6;
const long long mod=1e9+7;
const int inf=2147483647;
const int maxn=100005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}


int n,m;
ll w[maxn];

struct Edge{
	int u,v,w,next;
}e[maxn<<1];
int gcnt,head[maxn];
inline void init_graph(){
	gcnt=0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int w=0){
	e[gcnt]=Edge{u,v,w,head[u]};
	head[u]=gcnt++;
}


/* Heavy Path Decomposition */
// dfs序、深度、子树大小、父节点、重儿子、链顶
int dfsx,csid[maxn],csdep[maxn],cssize[maxn],csfa[maxn],csson[maxn],cstop[maxn];
// value need to maintain
ll csw[maxn];

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
	csw[dfsx]=w[u];
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


/* Normal Segment Tree */
#define ls i<<1
#define rs i<<1|1
struct SegmentTree
{
	struct Tree{
		int l,r;
		ll sum,ptg;
	}tr[maxn<<2];

	inline void push_up(int i){
		tr[i].sum=(tr[ls].sum+tr[rs].sum);
	}

	inline void push_down(int i){
		if(tr[i].ptg==0) return;
		ll k=tr[i].ptg;
		tr[ls].sum=tr[ls].sum+k*(tr[ls].r-tr[ls].l+1);
		tr[rs].sum=tr[rs].sum+k*(tr[rs].r-tr[rs].l+1);
		tr[ls].ptg+=k;
		tr[rs].ptg+=k;
		tr[i].ptg=0;
	}

	inline void build(int i,int l,int r){
		tr[i].l=l,tr[i].r=r;
		tr[i].ptg=0;
		if(tr[i].l==tr[i].r){
			tr[i].sum=csw[l];
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(i);
	}


	inline void addinterval(int i,int l,int r,ll k){
		if(tr[i].l>=l&&tr[i].r<=r){
			tr[i].sum=(tr[i].sum+k*(tr[i].r-tr[i].l+1));
			tr[i].ptg=(tr[i].ptg+k);
			return;
		}
		push_down(i);
		if(tr[ls].r>=l) addinterval(ls,l,r,k);
		if(tr[rs].l<=r) addinterval(rs,l,r,k);
		push_up(i);
	}

	inline ll getsum(int i,int l,int r){
		if(tr[i].l>=l&&tr[i].r<=r)
			return tr[i].sum;
		push_down(i);
		ll res=0;
		if(tr[ls].r>=l) res=(res+getsum(ls,l,r));
		if(tr[rs].l<=r) res=(res+getsum(rs,l,r));
		return res;
	}
}T;


inline void addp(int x,ll k){
	T.addinterval(1,csid[x],csid[x],k);
}

inline void addrt(int x,ll k){
	T.addinterval(1,csid[x],csid[x]+cssize[x]-1,k);
}

inline ll getrtsum(int x){
	int y=1;
	ll res=0;
	while(cstop[x]!=cstop[y]){
		if(csdep[cstop[x]]<csdep[cstop[y]])
			swap(x,y);
		res+=T.getsum(1,csid[cstop[x]],csid[x]);
		x=csfa[cstop[x]];
	}
	if(csdep[x]>csdep[y]) swap(x,y);
	res+=T.getsum(1,csid[x],csid[y]);
	return res;
}


int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%lld",&w[i]);
	init_graph();
	rep(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	csdfs1(1,-1,1);
	csdfs2(1,1);
	T.build(1,1,n);
	while(m--){
		int op,x,y;
		scanf("%d",&op);
		if(op==1) scanf("%d%d",&x,&y),addp(x,1ll*y);
		if(op==2) scanf("%d%d",&x,&y),addrt(x,1ll*y);
		if(op==3) scanf("%d",&x),printf("%lld\n",getrtsum(x));
	}
	return 0;
}