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
#define lson (i<<1)
#define rson (i<<1|1)
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
int n,m,r,p,op,x,y,z,w[maxn],wt[maxn];
int dfsx,csdep[maxn],csid[maxn],csfa[maxn],csson[maxn],cstop[maxn],cssize[maxn];

struct Stree
{
	int l,r,sum,ptg;
}tr[maxn<<2];

inline void push_up(int i){
	tr[i].sum=(tr[lson].sum+tr[rson].sum)%p;
}

inline void push_down(int i){
	if(!tr[i].ptg) return;
	int k=tr[i].ptg;
	tr[lson].ptg=(tr[lson].ptg+k)%p;
	tr[rson].ptg=(tr[rson].ptg+k)%p;
	tr[lson].sum=(tr[lson].sum+(tr[lson].r-tr[lson].l+1)*k)%p;
	tr[rson].sum=(tr[rson].sum+(tr[rson].r-tr[rson].l+1)*k)%p;
	tr[i].ptg=0;
}

inline void build(int i,int l,int r){
	tr[i].l=l,tr[i].r=r,tr[i].ptg=0;
	if(l==r){
		tr[i].sum=wt[l]%p;
		return;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	push_up(i);
}

inline void add(int i,int l,int r,int k){
	if(tr[i].l>=l&&tr[i].r<=r){
		tr[i].sum=(tr[i].sum+(tr[i].r-tr[i].l+1)*k)%p;
		tr[i].ptg=(tr[i].ptg+k)%p;
		return;
	}
	push_down(i);
	if(tr[lson].r>=l) add(lson,l,r,k);
	if(tr[rson].l<=r) add(rson,l,r,k);
	push_up(i);
}

inline int getsum(int i,int l,int r){
	if(tr[i].l>=l&&tr[i].r<=r) return tr[i].sum%p;
	push_down(i);
	int res=0;
	if(tr[lson].r>=l) res=(res+getsum(lson,l,r))%p;
	if(tr[rson].l<=r) res=(res+getsum(rson,l,r))%p;
	return res;
}

// 第一次dfs：处理出 深度、父亲、子树大小、重儿子
inline void dfs1(int u,int fath,int depth){
	csdep[u]=depth;
	csfa[u]=fath;
	cssize[u]=1;
	int maxsize=-1;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
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
	wt[dfsx]=w[u];
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

// 对x、y路径上所有节点权值+k
inline void addroute(int x,int y,int k){
	k%=p;
	while(cstop[x]!=cstop[y]){//如果不属于同一条重链
		if(csdep[cstop[x]]<csdep[cstop[y]]) swap(x,y);//设x所在链头部较深
		add(1,csid[cstop[x]],csid[x],k);
		x=csfa[cstop[x]];//x跳到所在链头部的父节点上，继续下去
	}
	//直到x、y在同一重链上
	if(csdep[x]>csdep[y]) swap(x,y);//设x较浅
	add(1,csid[x],csid[y],k);//对重链对应区间更新
}

inline int getroute(int x,int y){//类似修改操作
	int res=0;
	while(cstop[x]!=cstop[y]){
		if(csdep[cstop[x]]<csdep[cstop[y]]) swap(x,y);
		res=(res+getsum(1,csid[cstop[x]],csid[x]))%p;
		x=csfa[cstop[x]];
	}
	if(csdep[x]>csdep[y]) swap(x,y);
	res=(res+getsum(1,csid[x],csid[y]))%p;
	return res;
}

inline void addtree(int x,int k){
	add(1,csid[x],csid[x]+cssize[x]-1,k);
}

inline int gettree(int x){
	return getsum(1,csid[x],csid[x]+cssize[x]-1)%p;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&r,&p);
	init();
	rep(i,1,n) scanf("%d",&w[i]);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs1(r,-1,1);
	dfs2(r,r);
	build(1,1,n);
	rep(i,1,m){
		scanf("%d%d",&op,&x);
		if(op==1) scanf("%d%d",&y,&z),addroute(x,y,z);
		if(op==2) scanf("%d",&y),printf("%d\n",getroute(x,y));
		if(op==3) scanf("%d",&z),addtree(x,z);
		if(op==4) printf("%d\n",gettree(x));
	}
	return 0;
}//https://www.luogu.com.cn/problem/P3384