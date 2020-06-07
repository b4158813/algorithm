#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define All(x) (x).begin(),(x).end()
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
const double PI=acos(-1.0);
const double eps=1e-6;
const long long mod=1e9+7;
const int inf=0x7fffffff;
const int maxn=200005;
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

int n;

ll a[maxn],b[maxn],zuo,you,sum[maxn];

int main(){
	//freopen("test.in","r",stdin);
	read(n);
	rep(i,1,n){
		read(a[i]),read(b[i]);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	if(n&1)
		printf("%lld\n",b[n/2+1]-a[n/2+1]+1);
	else printf("%lld\n",(b[n/2]+b[n/2+1])-(a[n/2]+a[n/2+1])+1);
	return 0;
}