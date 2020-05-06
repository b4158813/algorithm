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

int n,k;
ll x,ans;
struct node
{
	ll val,h;
	bool operator <(const node& rhs)const{
		if(val==rhs.val) return h>rhs.h;
		return val>rhs.val;
	}
};
priority_queue<node> pq;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%lld",&x),pq.push(node{x,1});
	while((n-1)%(k-1)!=0) pq.push(node{0,1}),n++;
	while(n>1){
		// printf("size:%d\n",pq.size());
		ll temp=0,maxh=0;
		rep(i,1,k){
			temp+=pq.top().val;
			maxh=max(maxh,pq.top().h);
			pq.pop();
		}
		ans+=temp;
		pq.push(node{temp,maxh+1});
		n-=k-1;
	}
	printf("%lld\n%lld\n",ans,pq.top().h-1);

	return 0;
}