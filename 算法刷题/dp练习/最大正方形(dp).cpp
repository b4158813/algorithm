#include<bits/stdc++.h>
using namespace std;
#define LOCAL
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define All(x) (x).begin(),(x).end()
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int,int> PII;
const double PI=acos(-1.0);
const double eps=1e-6;
const long long mod=1e9+7;
const int inf=0x7fffffff;
const int maxn=100005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
// fast read
template<class T> void read(T &x) {
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}

int ans,n,m,dp[105][105],a[105][105];

int main(){
	#ifdef LOCAL
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
		clock_t begin = clock();
	#endif //LOCAL

	read(n),read(m);
	rep(i,1,n)
		rep(j,1,m)
			read(a[i][j]);
	rep(i,1,n){
		rep(j,1,m){
			if(a[i][j]==1)
				dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
			ans=max(dp[i][j],ans);
		}
	}
	printf("%d\n",ans);

	#ifdef LOCAL
		double used = 1000.0 * double(clock() - begin) / CLOCKS_PER_SEC - 200.0;
		if (used < 0) used = 0.0;
		printf("------------------------------\n");
		printf("Time used: %.2lf ms.\n", used);
	#endif
		
	return 0;
}