#include<bits/stdc++.h>
using namespace std;
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
const long long mod=998244353;
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

int n,s,a[maxn];
ll dp[3005][3005];
int main(){
	//freopen("test.in","r",stdin);
	read(n),read(s);
	rep(i,1,n) read(a[i]);
	// ll inv2=qpow(2,mod-2,mod);
	dp[0][0]=1;
	rep(i,1,n){
		rep(j,0,s){
			dp[i][j]=(dp[i][j]+dp[i-1][j]*2+((j>=a[i])?dp[i-1][j-a[i]]:0))%mod;
		}
	}
	printf("%lld\n",dp[n][s]%mod);
	return 0;
}