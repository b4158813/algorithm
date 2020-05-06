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
#define rep(i,a,b) for(register int i=a;i<=b;i++)
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
const int maxn=100005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,m;
db p1[1015][1015],p2[1015][1015],p3[1015][1015];
db dp[1015][1015];

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(dp,0,sizeof(dp));
		rep(i,1,n){
			rep(j,1,m){
				scanf("%lf%lf%lf",&p1[i][j],&p2[i][j],&p3[i][j]);
				// cin>>p1[i][j]>>p2[i][j]>>p3[i][j];
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(fabs(p1[i][j]-1.0)<eps) continue;
				dp[i][j]=(p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2.0)/(1.0-p1[i][j]);
			}
		}
		printf("%.3lf\n",dp[1][1]);
	}
	
	return 0;
}// http://acm.hdu.edu.cn/showproblem.php?pid=3853