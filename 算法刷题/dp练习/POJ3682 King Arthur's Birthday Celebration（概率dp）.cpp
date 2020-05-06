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

int k;
db p,f[maxn],F[maxn];

int main(){
	while(~scanf("%d",&k)&&k){
		scanf("%lf",&p);
		memset(f,0,sizeof(f));
		memset(F,0,sizeof(F));
		for(int i=k-1;i>=0;i--){
			f[i]=f[i+1]+1/p;
			F[i]=F[i+1]+2*f[i+1]+(2*(1-p)*f[i]+1.0)/p;
		}
		printf("%.3lf %.3lf\n",f[0],F[0]);
	}
	return 0;
}