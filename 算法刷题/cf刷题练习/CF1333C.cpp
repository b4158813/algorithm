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

int n,ist[maxn];
ll a[maxn];
map<ll,int> ma;

int main(){
	//freopen("test.in","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]),a[i]+=a[i-1];
	rep(i,0,n){
		if(!ma.count(a[i])) ma[a[i]]=i,ist[i]=-1;
		else{
			ist[i]=ma[a[i]];
			ma[a[i]]=i;
		}
	}
	int mx=-1;
	ll ans=0;
	// rep(i,1,n) printf("%d ",ist[i]);
	// cout<<endl;
	rep(i,0,n){
		mx=max(mx,ist[i]);
		ans+=(ll)(i-mx-1);
	}
	printf("%lld\n",ans);
	return 0;
}