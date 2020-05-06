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
const int maxn=300005;
ll qpow(ll x,ll y) {ll ans=1,base=x; while(y){if(y&1)ans=(ans*base)%mod;base=(base*base)%mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,q,l,r,k;
int mtg[maxn*50],ls[maxn*50],rs[maxn*50],sum[maxn*50],rt,ncnt;

inline void push_up(int o){
	sum[o]=sum[ls[o]]+sum[rs[o]];
}

inline void push_down(int &o,int l,int r){
	if(mtg[o]==-1) return;
	if(!ls[o]) ls[o]=++ncnt;
	if(!rs[o]) rs[o]=++ncnt;
	int mid=(l+r)>>1;
	sum[ls[o]]=mtg[o]*(mid-l+1);
	sum[rs[o]]=mtg[o]*(r-mid);
	mtg[ls[o]]=mtg[rs[o]]=mtg[o];
	mtg[o]=-1;
}

inline void to_(int &o,int l,int r,int L,int R,int k){
	if(!o) o=++ncnt;
	if(l>=L&&r<=R){
		sum[o]=k*(r-l+1);
		mtg[o]=k;
		return;
	}
	push_down(o,l,r);
	int mid=(l+r)>>1;
	if(mid>=L) to_(ls[o],l,mid,L,R,k);
	if(mid+1<=R) to_(rs[o],mid+1,r,L,R,k);
	push_up(o);
}

int main(){
	scanf("%d%d",&n,&q);
	memset(mtg,-1,sizeof(mtg));
	rep(i,1,q){
		scanf("%d%d%d",&l,&r,&k);
		if(k==2) to_(rt,1,n,l,r,0);
		else to_(rt,1,n,l,r,1);
		printf("%d\n",n-sum[rt]);
	}
	return 0;
}