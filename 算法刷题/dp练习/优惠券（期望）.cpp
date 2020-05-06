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
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
int n;

int count(ll x){
	int ans=0;
	while(x){
		ans++;
		x/=10;
	}
	return ans;
}

int main(){
	while(~scanf("%d",&n)){
		ll ans1=1,ans2=1;
		for(int i=2;i<=n;i++){
			ll tp=lcm(i,ans2);
			ll x1=tp/ans2,x2=tp/i;
			ans2=tp;
			ans1=ans1*x1+x2;
			ll tp2=gcd(ans1,ans2);
			ans1/=tp2,ans2/=tp2;
		}
		ans1*=n;
		ll tp2=gcd(ans1,ans2);
		ans1/=tp2,ans2/=tp2;
		if(ans2==1){
			printf("%lld\n",ans1);
			continue;
		}
		ll dai=ans1/ans2;
		if(dai) ans1%=ans2;
		int numfen=max(count(ans1),count(ans2)),numdai=count(dai);
		for(int i=0;i<=numdai;i++)
			printf(" ");
		printf("%lld\n%lld ",ans1,dai);
		for(int i=0;i<numfen;i++)
			printf("-");
		printf("\n");
		for(int i=0;i<=numdai;i++)
			printf(" ");
		printf("%lld\n",ans2);
	}
	return 0;
}// https://www.luogu.com.cn/problem/UVA10288