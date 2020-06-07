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

ll n,cnt,ans;
pair<ll,int> yin[maxn];

int main(){
	//freopen("test.in","r",stdin);
	read(n);
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			yin[++cnt].first=i;
			while(n%i==0) n/=i,yin[cnt].second++;
		}
	}
	if(n!=1) yin[++cnt].first=n,yin[cnt].second++;
	for(int i=1;i<=cnt;i++){
		int dd=1;
		for(int j=1;j<=yin[i].second;j+=++dd){
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}