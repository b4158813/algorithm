#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(register int i=a;i<=b;i++)
#define All(x) (x).begin(),(x).end()
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef double db;
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

int _;
char a[55][55];
int n;

int main(){
	//freopen("test.in","r",stdin);
	for(scanf("%d",&_);_;_--){
		scanf("%d",&n);
		rep(i,0,53)
			rep(j,0,53)
				a[i][j]='-1';
		rep(i,1,n){
			rep(j,1,n){
				cin>>a[i][j];
			}
			// getchar();
		}
		bool f=true;
		rep(i,1,n){
			rep(j,1,n){
				if(a[i][j]=='1'){
					if(a[i+1][j]=='-1'||a[i+1][j]=='1'||a[i][j+1]=='-1'||a[i][j+1]=='1'){
						continue;
					}else f=false;
				}
			}
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}