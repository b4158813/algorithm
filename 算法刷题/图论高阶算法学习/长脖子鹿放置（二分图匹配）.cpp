#include<bits/stdc++.h>
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
const int maxn=500005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,m,k,nope[305][305];
int d1[]={-3,-3,-1,-1,1,1,3,3};
int d2[]={-1,1,-3,3,-3,3,-1,1};

struct Edge{
	int u,v,w,next;
}e[maxn<<1];
int gcnt,head[maxn];
inline void addedge(int u,int v,int w=0){
	e[++gcnt]=Edge{u,v,w,head[u]};
	head[u]=gcnt;
}

int idx,have[maxn],used[maxn];
inline bool Hungary(int u){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if(used[v]!=idx){
			used[v]=idx;
			if(!have[v]||Hungary(have[v])){
				have[v]=u;
				return true;
			}
		}
	}
	return false;
}

inline int getnum(int x,int y){
	return (x-1)*m+y;
}

inline bool in(int x,int y){
	return (x>=1&&x<=n&&y>=1&&y<=m);
}

int main(){
	int x,y,nnn=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		if(!nope[x][y]) nnn++;
		nope[x][y]=1;
	}
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=m;j++){
			if(nope[i][j]) continue;
			for(int k=0;k<8;k++){
				int dx=i+d1[k];
				int dy=j+d2[k];
				if(in(dx,dy)&&(!nope[dx][dy])){
					addedge(getnum(i,j),getnum(dx,dy));
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=m;j++){
			if(!nope[i][j]){
				idx++;
				if(Hungary(getnum(i,j))) ans++;
			}
		}
	}
	printf("%d\n",n*m-nnn-ans);
	return 0;
}

/*
8 7 5
1 1
5 4
2 3
4 7
8 3
*/