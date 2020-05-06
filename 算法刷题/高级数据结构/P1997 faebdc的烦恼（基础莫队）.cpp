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
const int maxn=200005;
ll qpow(ll x,ll y) {ll ans=1,base=x; while(y){if(y&1)ans=(ans*base)%mod;base=(base*base)%mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,m,st[maxn],en[maxn],bel[maxn],blk,cnt[maxn],ge[maxn],a[maxn],ans[maxn],now;
struct que
{
	int l,r,id;
}q[maxn];
bool cmp(que x1,que x2){
	return bel[x1.l]==bel[x2.l]?bel[x1.r]<bel[x2.r]:bel[x1.l]<bel[x2.l];
}
inline void init_blk(){
	blk=sqrt(n);
	rep(i,1,blk) st[i]=n/blk*(i-1)+1,en[i]=n/blk*i;
	en[blk]=n;
	rep(i,1,blk)
		rep(j,st[i],en[i])
			bel[j]=i;
}
inline void add(int pos){
	--ge[cnt[a[pos]]];
	++cnt[a[pos]];
	++ge[cnt[a[pos]]];
	now=max(now,cnt[a[pos]]);
}
inline void del(int pos){
	if((now==cnt[a[pos]])&&(ge[cnt[a[pos]]]==1)) now--;
	--ge[cnt[a[pos]]];
	--cnt[a[pos]];
	++ge[cnt[a[pos]]];

}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&a[i]);
	init_blk();
	rep(i,1,m) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	rep(i,1,m){
		int tl=q[i].l,tr=q[i].r;
		while(l<tl) del(l++);
		while(l>tl) add(--l);
		while(r<tr) add(++r);
		while(r>tr) del(r--);
		ans[q[i].id]=now; 
	}
	rep(i,1,m) printf("%d\n",ans[i]);
	return 0;
}