#include<bits/stdc++.h>
using namespace std;
#define DEBUG cout<<"ha"<<endl;
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
const int inf=0x7fffffff;
const int maxn=100005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n;

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
int csw[maxn],w[maxn];

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
	csw[dfsx]=u;
	cstop[u]=topf;
	if(!csson[u]) return;
	csdfs2(csson[u],topf);
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=csfa[u]&&v!=csson[u])
			csdfs2(v,v);
	}
}

/* Normal Segment Tree */

struct SegmentTree
{	
	#define ls i<<1
	#define rs i<<1|1
	struct Tree{
		int l,r;
		ll sum,ptg;
	}tr[maxn<<2];

	inline void push_up(int i){
		tr[i].sum=(tr[ls].sum+tr[rs].sum)%mod;
	}

	inline void push_down(int i){
		if(tr[i].ptg==-1) return;
		ll k=tr[i].ptg;
		tr[ls].sum=(k*(tr[ls].r-tr[ls].l+1));
		tr[rs].sum=(k*(tr[rs].r-tr[rs].l+1));
		tr[ls].ptg=k;
		tr[rs].ptg=k;
		tr[i].ptg=-1;
	}

	inline void build(int i,int l,int r){
		tr[i].l=l,tr[i].r=r;
		tr[i].ptg=-1;
		if(tr[i].l==tr[i].r){
			tr[i].sum=0;
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(i);
	}

	inline void changeinterval(int i,int l,int r,ll k){
		if(tr[i].l>=l&&tr[i].r<=r){
			tr[i].sum=k*(tr[i].r-tr[i].l+1);
			tr[i].ptg=k;
			return;
		}
		push_down(i);
		if(tr[ls].r>=l) changeinterval(ls,l,r,k);
		if(tr[rs].l<=r) changeinterval(rs,l,r,k);
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


inline ll getsumroot(int x){
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

inline ll getsumson(int x){
	return T.getsum(1,csid[x],csid[x]+cssize[x]-1);
}

inline void changeroot(int x){
	int y=1;
	while(cstop[x]!=cstop[y]){
		if(csdep[cstop[x]]<csdep[cstop[y]])
			swap(x,y);
		T.changeinterval(1,csid[cstop[x]],csid[x],1);
		x=csfa[cstop[x]];
	}
	if(csdep[x]>csdep[y]) swap(x,y);
	T.changeinterval(1,csid[x],csid[y],1);
}

inline void changeson(int x){
	T.changeinterval(1,csid[x],csid[x]+cssize[x]-1,0);
}

int main(){
	scanf("%d",&n);
	init_graph();
	rep(i,2,n){
		int x;
		scanf("%d",&x);
		x++;
		addedge(i,x);
		addedge(x,i);
	}
	csdfs1(1,-1,1);
	csdfs2(1,1);
	T.build(1,1,n);

	// DEBUG;
	int q;
	scanf("%d",&q);
	// DEBUG;
	string s;
	int x;
	while(q--){
		cin>>s>>x;
		x++;
		// DEBUG;
		if(s=="install"){
			// DEBUG;
			ll before=getsumroot(x);
			changeroot(x);
			ll after=getsumroot(x);
			printf("%lld\n",after-before);
		}else{
			ll before=getsumson(x);
			changeson(x);
			ll after=getsumson(x);
			printf("%lld\n",before-after);
		}
	}
	return 0;
}