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
const double eps=1e-9;
const long long mod=1e9+7;
const int inf=2147483647;
const int maxn=100005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int _,n;
vector<int > E[maxn];
db k[maxn],e[maxn];
db a[maxn],b[maxn],c[maxn];

bool dfs(int u,int fa){
	a[u]=k[u];
	b[u]=(1-k[u]-e[u])/E[u].size();
	c[u]=1-k[u]-e[u];
	db tp=0;
	for(int i=0;i<(int)E[u].size();i++){
		int v=E[u][i];
		if(v!=fa){
			if(!dfs(v,u)) return false;
			a[u]+=(1-k[u]-e[u])/E[u].size()*a[v];
			c[u]+=(1-k[u]-e[u])/E[u].size()*c[v];
			tp+=(1-k[u]-e[u])/E[u].size()*b[v];
		}
	}
	if(fabs(1-tp)<eps) return false;
	a[u]/=1-tp;
	b[u]/=1-tp;
	c[u]/=1-tp;
	return true;
}

int main(){
	int Ca=0;
	for(scanf("%d",&_);_;_--){
		rep(i,1,n) E[i].clear();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		rep(i,1,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			E[x].pb(y),E[y].pb(x);
		}
		rep(i,1,n){
			scanf("%lf%lf",&k[i],&e[i]);
			k[i]/=100,e[i]/=100;
		}
		printf("Case %d: ",++Ca);
		if(dfs(1,-1)&&fabs(1-a[1])>eps) printf("%.12lf\n",c[1]/(1-a[1]));
		else printf("impossible\n");
	}
	return 0;
}// http://acm.hdu.edu.cn/showproblem.php?pid=4035