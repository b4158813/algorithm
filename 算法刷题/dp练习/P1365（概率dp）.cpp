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
const int maxn=300005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n;
db p[maxn],f[maxn],ff[maxn];
char s[maxn];

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n){
		if(s[i]=='?') p[i]=0.5;
		if(s[i]=='o') p[i]=1;
		if(s[i]=='x') p[i]=0;
	}
	ff[1]=f[1]=p[1];
	rep(i,2,n){
		f[i]=(f[i-1]+1)*p[i];
		ff[i]=ff[i-1]+(2*f[i-1]+1)*p[i];
	}
	printf("%.4lf\n",ff[n]);
	return 0;
}// https://www.luogu.com.cn/problem/P1365
