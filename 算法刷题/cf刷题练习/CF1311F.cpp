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
template<class T> void read(T &x){
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int n,vv[maxn];
ll c[maxn][2];
struct node
{
	int x,v;
}a[maxn];
inline int lowbit(int x){return x&-x;};
inline void add(int i,int k,ll val){
	while(i<=n) c[i][k]+=val,i+=lowbit(i);
}
inline ll getsum(int i,int k){
	ll res=0;
	while(i){
		res+=c[i][k];
		i-=lowbit(i);
	}
	return res;
}
bool cmp(node x1,node x2){
	return x1.x<x2.x;
}

int main(){
	//freopen("test.in","r",stdin);
	read(n);
	rep(i,1,n) read(a[i].x);
	rep(i,1,n) read(a[i].v),vv[i]=a[i].v;
	sort(vv+1,vv+1+n);
	int len=unique(vv+1,vv+1+n)-vv-1;
	rep(i,1,n){
		a[i].v=lower_bound(vv+1,vv+1+len,a[i].v)-vv;
	}
	sort(a+1,a+1+n,cmp);
	ll ans=0;
	rep(i,1,n){
		ans+=getsum(a[i].v,0)*a[i].x-getsum(a[i].v,1);
		add(a[i].v,0,1ll*1);
		add(a[i].v,1,1ll*a[i].x);
	}
	printf("%lld\n",ans);
	return 0;
}