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

int _,n;
db dp[maxn],p;

int main(){
	for(scanf("%d",&_);_;_--){
		memset(dp,0,sizeof(dp));
		scanf("%d%lf",&n,&p);
		for(int i=n-1;i>=1;i--){
			db P=2.0*i*(n-i)/(n-1)/n*p;
			dp[i]=(P*dp[i+1]+1.0)/P;
		}
		printf("%.3lf\n",dp[1]);
	}
	return 0;
}// https://zoj.pintia.cn/problem-sets/91827364500/problems/91827369029