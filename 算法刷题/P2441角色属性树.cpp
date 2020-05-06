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
const int maxn=200005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,k,fa[maxn],w[maxn],x,y,op;
VI vec[maxn];

inline int getfashu(int x){
	int t=w[x];
	while(fa[x]){
		if(gcd(t,w[fa[x]])!=1) return fa[x];
		x=fa[x];
	}
	return -1;
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&w[i]);
	rep(i,1,n-1) scanf("%d%d",&x,&y),fa[y]=x;
	rep(i,1,k){
		scanf("%d",&op);
		if(op==1) scanf("%d",&x),printf("%d\n",getfashu(x));
		else scanf("%d%d",&x,&y),w[x]=y;
	}
	return 0;
}