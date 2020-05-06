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
const int maxn=500005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int _,n,k1,k2,k3,a,b,c;
double p[maxn],A[maxn],B[maxn];

void dfs(int i){
	if(A[i]) return;
	if(i>n){
		A[i]=B[i]=0;
		return;
	}
	A[i]=p[0],B[i]=1;
	rep(k,3,k1+k2+k3){
		dfs(i+k);
		A[i]+=p[k]*A[i+k];
		B[i]+=p[k]*B[i+k];
	}
}

int main(){
	for(scanf("%d",&_);_;_--){
		memset(p,0,sizeof(p));
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
		p[0]=1.0/(k1*k2*k3);
		rep(i,1,k1){
			rep(j,1,k2){
				rep(k,1,k3){
					if(i!=a||j!=b||k!=c)
						p[i+j+k]+=p[0];
				}
			}
		}
		dfs(0);
		printf("%.16lf\n",B[0]/(1-A[0]));
	}
	return 0;
}// https://zoj.pintia.cn/problem-sets/91827364500/problems/91827368253