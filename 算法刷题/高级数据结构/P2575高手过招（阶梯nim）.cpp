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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define All(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef pair<int,int> PII;
const db PI=acos(-1.0);
const db eps=1e-6;
const ll mod=1e9+7;
const int inf=2147483647;
const int maxn=100005;
ll qpow(ll x,ll y) {ll ans=1,base=x; while(y){if(y&1)ans=(ans*base)%mod;base=(base*base)%mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int _,n,pan[21];

int main(){
	for(scanf("%d",&_);_;_--){
		scanf("%d",&n);
		int x,k;
		int ans2=0;
		rep(i,1,n){
			memset(pan,0,sizeof(pan));
			scanf("%d",&x);
			rep(j,1,x){
				scanf("%d",&k);
				pan[k]=1;
			}
			int tp=0,cnt=0,ans1=0;
			int j=20;
			while(pan[j]) j--;
			j--;
			for(;j>=0;j--){
				if(!pan[j]){
					++cnt;
					if(cnt&1) ans1^=tp;
					tp=0;
				}else tp++;
			}
			ans2^=ans1;
		}
		ans2?puts("YES"):puts("NO");
	}
	return 0;
}