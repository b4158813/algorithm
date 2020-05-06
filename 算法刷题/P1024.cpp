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

db a,b,c,d;

inline db df(db x){
	return 3*a*x*x+2*b*x+c;
}

inline db f(db x){
	return a*x*x*x+b*x*x+c*x+d;
}

inline void solve(){
	db l=-100,r=100;
	db ji=0,ez=0,ey=0;
	db ans1,ans2,ans3;
	if(a>0){
		while(r-l>eps){
			db mid1=l+(r-l)/3;
			db mid2=r-(r-l)/3;
			if(df(mid1)<df(mid2)) ji=mid2,r=mid2;
			else l=mid1;
		}
		l=-100,r=ji;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(df(mid)>0) ez=mid,l=mid;
			else r=mid;
		}
		l=ji,r=100;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(df(mid)>0) ey=mid,r=mid;
			else l=mid;
		}

		l=-100,r=ez;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(f(mid)<0) ans1=mid,l=mid;
			else r=mid;
		}
		l=ez,r=ey;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(f(mid)<0) ans2=mid,r=mid;
			else l=mid;
		}
		l=ey,r=100;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(f(mid)<0) ans3=mid,l=mid;
			else r=mid;
		}
	}else{
		while(r-l>eps){
			db mid1=l+(r-l)/3;
			db mid2=r-(r-l)/3;
			if(df(mid1)<df(mid2)) ji=mid1,l=mid1;
			else r=mid2;
		}
		l=-100,r=ji;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(df(mid)>0) ez=mid,r=mid;
			else l=mid;
		}
		l=ji,r=100;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(df(mid)>0) ey=mid,l=mid;
			else r=mid;
		}

		l=-100,r=ez;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(f(mid)<0) ans1=mid,r=mid;
			else l=mid;
		}
		l=ez,r=ey;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(f(mid)<0) ans2=mid,l=mid;
			else r=mid;
		}
		l=ey,r=100;
		while(r-l>eps){
			db mid=(l+r)/2;
			if(f(mid)<0) ans3=mid,r=mid;
			else l=mid;
		}
	}
	printf("%.2lf %.2lf %.2lf\n",ans1,ans2,ans3);
}

int main(){
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	solve();
	return 0;
}