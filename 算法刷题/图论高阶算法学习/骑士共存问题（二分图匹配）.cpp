#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
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
const int maxn=500005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,k,nope[305][305];
int dir[][2]={{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1}};


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
	return (x-1)*n+y;
}

inline bool in(int x,int y){
	return (x>=1&&x<=n&&y>=1&&y<=n);
}

int main(){
	int x,y;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		nope[x][y]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=(i&1)?1:2;j<=n;j+=2){
			if(nope[i][j]) continue;
			for(int k=0;k<8;k++){
				int dx=i+dir[k][0];
				int dy=j+dir[k][1];
				if(in(dx,dy)&&!nope[dx][dy]){
					addedge(getnum(i,j),getnum(dx,dy));
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=(i&1)?1:2;j<=n;j+=2){
			if(!nope[i][j]){
				idx++;
				if(Hungary(getnum(i,j))) ans++;
			}
		}
	}
	printf("%d\n",n*n-k-ans);
	return 0;
}
