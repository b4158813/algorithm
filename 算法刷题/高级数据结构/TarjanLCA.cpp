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
const int maxn=1000005;
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
int Fa[maxn];
inline int find(int x){return x==Fa[x]?x:Fa[x]=find(Fa[x]);}
int n,m,s,cnt,head[maxn];
int headq[maxn],qcnt,ans[maxn];
bool vis[maxn];
struct Q
{
	int to,next,id;
}q[maxn];
struct Edge
{
	int u,v,w,next;
}e[maxn<<1];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
inline void addask(int u,int v,int id){
	q[qcnt]=Q{v,headq[u],id};
	headq[u]=qcnt++;
}
inline void init(){
	memset(head,-1,sizeof(head));
	memset(headq,-1,sizeof(headq));
	rep(i,1,n) Fa[i]=i;
	cnt=qcnt=0;
}
inline void TarjanLCA(int u){
	vis[u]=1;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!vis[v]){
			TarjanLCA(v);
			Fa[find(v)]=u;
		}
	}
	for(int i=headq[u];~i;i=q[i].next){
		int to=q[i].to;
		if(vis[to]){
			ans[q[i].id]=find(to);
		}
	}
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
	rep(i,1,m){
		x=read(),y=read();
		addask(x,y,i);
		addask(y,x,i);
	}
	TarjanLCA(s);
	rep(i,1,m) write(ans[i]),putchar('\n');
	return 0;
}