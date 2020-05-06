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

int n,m,blk,a[maxn],b[maxn],st[maxn],en[maxn],bel[maxn],cnt[maxn],ge[maxn];
ll Ans[maxn],ans;
struct Q
{
	int l,r,id;
}q[maxn];
bool cmp(Q x1,Q x2){
	return bel[x1.l]^bel[x2.l]?bel[x1.l]<bel[x2.l]:((bel[x1.l]&1)?x1.r<x2.r:x1.r>x2.r);
}
inline void init_blk(){
	blk=sqrt(n);
	rep(i,1,blk) st[i]=n/blk*(i-1)+1,en[i]=n/blk*i;
	en[blk]=n;
	rep(i,1,blk){
		rep(j,st[i],en[i]) bel[j]=i;
	}
	// 离散化
	sort(b+1,b+1+n);
	int len=unique(b+1,b+1+n)-b-1;
	rep(i,1,n){
		a[i]=lower_bound(b+1,b+1+len,a[i])-b;
		// printf("%d ",a[i]);
	}
}
inline void add(int pos){
	--ge[cnt[a[pos]]];
	++cnt[a[pos]];
	++ge[cnt[a[pos]]];
	ans=max(ans,1ll*cnt[a[pos]]);
}
inline void del(int pos){
	if(cnt[a[pos]]==ans&&ge[cnt[a[pos]]]==1) ans--;
	--ge[cnt[a[pos]]];
	--cnt[a[pos]];
	++ge[cnt[a[pos]]];
}
int main(){
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&a[i]),b[i]=a[i];
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
		Ans[q[i].id]=-ans;
	}
	rep(i,1,m) printf("%lld\n",Ans[i]);
	return 0;
}

/*
7 5
1 2 3 3 3 4 5
1 2
2 5
6 7
1 7
5 5

-1
-3
-1
-3
-1
*/