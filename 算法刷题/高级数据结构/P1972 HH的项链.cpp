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
const int maxn=1000005;
ll qpow(ll x,ll y) {ll ans=1,base=x; while(y){if(y&1)ans=(ans*base)%mod;base=(base*base)%mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
inline ll read() {//快读
	ll kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}

void write(ll x){//快写
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}

int n,m,a[maxn],blk,st[maxn],en[maxn],bel[maxn],now;
int ans[maxn],cnt[maxn];
struct Q{
	int l,r,id;
}q[maxn];
bool cmp(Q x1,Q x2){
	return bel[x1.l]^bel[x2.l]?bel[x1.l]<bel[x2.l]:((bel[x1.l]&1)?x1.r<x2.r:x1.r>x2.r);
}

inline void init_blk(int n){
	blk=sqrt(n);
	rep(i,1,blk){
		st[i]=n/blk*(i-1)+1;
		en[i]=n/blk*i;
	}
	en[blk]=n;
	rep(i,1,blk){
		rep(j,st[i],en[i]){
			bel[j]=i;
		}
	}
}
inline void del(int pos){
	--cnt[a[pos]];
	if(!cnt[a[pos]]) --now;
}
inline void add(int pos){
	if(!cnt[a[pos]]) ++now;
	++cnt[a[pos]];
}
int main(){
	n=read();
	rep(i,1,n) a[i]=read();
	init_blk(n);
	m=read();
	rep(i,1,m){
		q[i].l=read(),q[i].r=read();
		q[i].id=i;
	}
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
	rep(i,1,m) write(ans[i]),putchar('\n');
	return 0;
}