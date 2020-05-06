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
const int maxn=300005;
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

int n,m,lcafa[maxn][25],sum[maxn][25],head[maxn],dep[maxn],LG[maxn],cnt;
int longest,dfscnt,treediff[maxn],sta[maxn],top;
struct Edge
{
	int u,v,w,next;
}e[maxn<<1];
struct Q
{
	int u,v,lca,routesum;
}q[maxn];
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt++;
}
void dfs1(int u,int fath){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v,w=e[i].w;
		if(v!=fath){
			dep[v]=dep[u]+1;
			lcafa[v][0]=u;
			sum[v][0]=w;
			dfs1(v,u);
		}
	}
}

inline int LCA(int x,int y,int &Sum){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){
		Sum+=sum[x][LG[dep[x]-dep[y]]];
		x=lcafa[x][LG[dep[x]-dep[y]]];
	}
	if(x==y) return x;
	for(int i=LG[dep[x]];i>=0;i--){
		if(lcafa[x][i]!=lcafa[y][i]){
			Sum+=sum[x][i]+sum[y][i];
			x=lcafa[x][i];
			y=lcafa[y][i];
		}
	}
	Sum+=sum[x][0]+sum[y][0];
	return lcafa[x][0];
}

inline int dfs2(int u,int fath){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			treediff[u]+=dfs2(v,u);
		}
	}
	if(treediff[u]==dfscnt){
		sta[++top]=sum[u][0];
	}
	return treediff[u];
}

inline bool check(int x){
	memset(treediff,0,sizeof(treediff));
	int maxh=0;
	dfscnt=0;
	rep(i,1,m){
		if(q[i].routesum>x){
			dfscnt++;
			treediff[q[i].u]++;
			treediff[q[i].v]++;
			treediff[q[i].lca]-=2;
		}
	}
	dfs2(1,0);
	while(top){
		maxh=max(maxh,sta[top--]);
	}
	return longest-maxh>x;
}

int main(){
	// freopen("P2680_13.in","r",stdin);
	n=read(),m=read();
	memset(head,-1,sizeof(head));
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}

	rep(i,1,n) LG[i]=log2(i);
	dfs1(1,0);
	// printf("ok\n");
	// exit(0);
	rep(i,1,24){
		rep(j,1,n){
			lcafa[j][i]=lcafa[lcafa[j][i-1]][i-1];
			sum[j][i]=sum[j][i-1]+sum[lcafa[j][i-1]][i-1];
		}
	}
	rep(i,1,m){
		q[i].u=read(),q[i].v=read();
		q[i].lca=LCA(q[i].u,q[i].v,q[i].routesum);
		longest=max(longest,q[i].routesum);
	}

	int l=0,r=longest;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	write(l),putchar('\n');
	return 0;
}