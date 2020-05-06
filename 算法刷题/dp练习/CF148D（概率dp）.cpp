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

int w,b;
double dp[1005][1005];

int main(){
	scanf("%d%d",&w,&b);
	rep(i,1,w){
		dp[i][0]=1;
		dp[i][1]=i*1.0/(i+1);
	}
	for(int i=1;i<=w;i++){
		for(int j=2;j<=b;j++){
			dp[i][j]=i*1.0/(i+j)+j*1.0/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*dp[i-1][j-2];
			if(j>2) dp[i][j]+=(j*1.0/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*dp[i][j-3]);
		}
	}
	printf("%.9lf\n",dp[w][b]);
	return 0;
}