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

int deg1[maxn],deg2[maxn];
double dp[maxn];

inline void toposort(){
	queue<int> q;
	q.push(n);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			dp[v]+=(dp[u]+1.0*w)/deg1[v];
			if(deg2[v]){
				deg2[v]--;
				if(!deg2[v])
					q.push(v);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	init_graph();
	rep(i,1,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(y,x,z);
		deg1[x]++,deg2[x]++;
	}
	toposort();
	printf("%.2lf\n",dp[1]);
	return 0;
}