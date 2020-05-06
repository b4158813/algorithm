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
const int maxn=500005;
ll qpow(ll x,ll y,ll Mod=1) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans%Mod;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,q,l,r,k,sum;

struct odtnode // ODT Tree
{
	ll l,r;
	mutable ll v;
	odtnode(ll L,ll R=-1,ll V=0):l(L),r(R),v(V){}
	bool operator <(const odtnode &rhs)const{
		return l<rhs.l;
	}
};

set<odtnode> odt;

set<odtnode>::iterator split(ll pos){
	auto it=odt.lower_bound(odtnode(pos));
	if(it!=odt.end()&&it->l==pos) return it;
	it--;
	ll l=it->l,r=it->r,v=it->v;
	odt.erase(it);
	odt.insert(odtnode(l,pos-1,v));
	return odt.insert(odtnode(pos,r,v)).first;
}

inline void modify(ll l,ll r,ll k){
	auto itr=split(r+1),itl=split(l);
	auto it=itl;
	for(;it!=itr;it++){
		sum-=it->v*(it->r-it->l+1);
	}
	odt.erase(itl,itr);
	odt.insert(odtnode(l,r,k));
	sum+=k*(r-l+1);
}

int main(){
	scanf("%d%d",&n,&q);
	odt.insert(odtnode{1,n,0});
	sum=0;
	rep(i,1,q){
		scanf("%d%d%d",&l,&r,&k);
		if(k==1) modify(l,r,1);
		else modify(l,r,0);
		printf("%d\n",n-sum);
	}
	return 0;
}