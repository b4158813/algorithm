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
#define rep(i,a,b) for(register int i=a;i<=b;i++)
#define All(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int,int> PII;
const double PI=acos(-1.0);
const double eps=1e-6;
const long long mod=1e9+7;
const int inf=2147483647;
const int maxn=30005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,q,w[maxn];

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
int csw[maxn];

/* Normal Segment Tree */

struct SegmentTree
{	
	#define ls i<<1
	#define rs i<<1|1
	struct Tree{
		int l,r;
		ll sum,maxh;
	}tr[maxn<<2];

	inline void push_up(int i){
		tr[i].sum=(tr[ls].sum+tr[rs].sum);
		tr[i].maxh=max(tr[ls].maxh,tr[rs].maxh);
	}

	inline void build(int i,int l,int r){
		tr[i].l=l,tr[i].r=r;
		if(tr[i].l==tr[i].r){
			tr[i].sum=csw[l];
			tr[i].maxh=csw[l];
			// printf("%dha",tr[i].maxh);
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(i);
	}

	inline void changepoint(int i,int pos,ll k){
		if(tr[i].l==tr[i].r){
			tr[i].sum=k;
			tr[i].maxh=k;
			return;
		}
		if(tr[ls].r>=pos) changepoint(ls,pos,k);
		else changepoint(rs,pos,k);
		push_up(i);
	}

	inline ll getsum(int i,int l,int r){
		if(tr[i].l>=l&&tr[i].r<=r)
			return tr[i].sum;
		ll res=0;
		if(tr[ls].r>=l) res=(res+getsum(ls,l,r));
		if(tr[rs].l<=r) res=(res+getsum(rs,l,r));
		return res;
	}

	inline ll getmax(int i,int l,int r){
		if(tr[i].l>=l&&tr[i].r<=r)
			return tr[i].maxh;
		ll res=-inf;
		if(tr[ls].r>=l) res=max(res,getmax(ls,l,r));
		if(tr[rs].l<=r) res=max(res,getmax(rs,l,r));
		return res;
	}
}T;

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

inline ll getmaxroute(int x,int y){
	ll res=-inf;
	while(cstop[x]!=cstop[y]){
		if(csdep[cstop[x]]<csdep[cstop[y]]) swap(x,y);
		res=max(res,T.getmax(1,csid[cstop[x]],csid[x]));
		x=csfa[cstop[x]];
	}
	if(csdep[x]>csdep[y]) swap(x,y);
	res=max(res,T.getmax(1,csid[x],csid[y]));
	return res;
}

inline ll getsumroute(int x,int y){
	ll res=0;
	while(cstop[x]!=cstop[y]){
		if(csdep[cstop[x]]<csdep[cstop[y]]) swap(x,y);
		res+=T.getsum(1,csid[cstop[x]],csid[x]);
		x=csfa[cstop[x]];
	}
	if(csdep[x]>csdep[y]) swap(x,y);
	res+=T.getsum(1,csid[x],csid[y]);
	return res;
}

inline void change(int x,int k){
	T.changepoint(1,csid[x],k);
}

int main(){
	scanf("%d",&n);
	init_graph();
	rep(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	rep(i,1,n) scanf("%d",&w[i]);

	csdfs1(1,-1,1);
	csdfs2(1,1);

	T.build(1,1,n);

	scanf("%d",&q);
	while(q--){
		string s;
		int u,v;
		cin>>s;
		scanf("%d%d",&u,&v);
		if(s=="CHANGE") change(u,v);
		if(s=="QMAX") printf("%lld\n",getmaxroute(u,v));
		if(s=="QSUM") printf("%lld\n",getsumroute(u,v));
	}
	return 0;
}