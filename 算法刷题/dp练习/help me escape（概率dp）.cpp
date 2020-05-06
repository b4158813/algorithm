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

int n,f,c[maxn],t[maxn];
double dp[maxn];

int main(){
	while(~scanf("%d%d",&n,&f)){
		memset(dp,0,sizeof(dp));
		rep(i,1,n)
			scanf("%d",&c[i]),
			t[i]=floor((1.0+sqrt(5.0))/2.0*c[i]*c[i]);

		for(int i=30000;i>=f;i--){
			for(int j=1;j<=n;j++){
				if(i>c[j]) dp[i]+=1.0*t[j]/n;
				else dp[i]+=(1.0+1.0*dp[i+c[j]])/n;
			}
		}
		printf("%.3lf\n",dp[f]);
	}
	return 0;
}// https://vjudge.net/problem/ZOJ-3640