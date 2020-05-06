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
const double PI=acos(-1.0);
const double eps=1e-6;
const long long mod=1e9+7;
const int inf=2147483647;
const int maxn=200005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,m,op,x,y;
ll a[maxn];
/* Normal Segment Tree */
#define ls i<<1
#define rs i<<1|1
struct SegmentTree
{
	struct Tree{
		int l,r;
		ll psum,sum;
	}tr[maxn<<2];

	inline void push_up(int i){
		tr[i].sum=(tr[ls].sum+tr[rs].sum)%mod;
		tr[i].psum=(tr[ls].psum+tr[rs].psum)%mod;
	}

	inline void build(int i,int l,int r){
		tr[i].l=l,tr[i].r=r;
		if(tr[i].l==tr[i].r){
			tr[i].sum=a[l]%mod;
			tr[i].psum=a[l]*a[l]%mod;
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(i);
	}

	inline void changep(int i,int pos,ll k){
		if(tr[i].l==tr[i].r){
			tr[i].sum=k%mod;
			tr[i].psum=k*k%mod;
			return;
		}
		if(tr[ls].r>=pos) changep(ls,pos,k);
		else changep(rs,pos,k);
		push_up(i);
	}

	inline ll getsum(int i,int l,int r){
		if(tr[i].l>=l&&tr[i].r<=r)
			return tr[i].sum%mod;
		ll res=0;
		if(tr[ls].r>=l) res=(res+getsum(ls,l,r))%mod;
		if(tr[rs].l<=r) res=(res+getsum(rs,l,r))%mod;
		return res%mod;
	}

	inline ll getpsum(int i,int l,int r){
		if(tr[i].l>=l&&tr[i].r<=r)
			return tr[i].psum%mod;
		ll res=0;
		if(tr[ls].r>=l) res=(res+getpsum(ls,l,r))%mod;
		if(tr[rs].l<=r) res=(res+getpsum(rs,l,r))%mod;
		return res%mod;
	}

	inline ll getstd(int l,int r){
		ll res=0;
		ll inv=qpow(r-l+1,mod-2,mod)%mod;
		ll sum=getsum(1,l,r)%mod;
		ll psum=getpsum(1,l,r)%mod;
		ll ave=sum*inv%mod;
		res=((psum*inv%mod-ave*ave%mod)%mod+mod+mod+mod)%mod;
		return res%mod;
	}
}T;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	T.build(1,1,n);
	while(m--){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) T.changep(1,x,y);
		else printf("%lld\n",T.getstd(x,y));
	}

	return 0;
}