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

int n,m,vmax;
ll seed;

inline ll rnd(){
	ll ret=seed;
	seed=(seed*7+13)%mod;
	return ret;
}

#define IT set<odtnode>::iterator
struct odtnode
{
	int l,r;
	mutable ll v;
	odtnode(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
	bool operator <(const odtnode& rhs)const{
		return l<rhs.l;
	}
};
set<odtnode> odt;

inline IT split(int pos){
	IT it=odt.lower_bound(odtnode(pos));
	if(it!=odt.end()&&it->l==pos) return it;
	it--;
	int l=it->l,r=it->r;
	ll v=it->v;
	odt.erase(it);
	odt.insert(odtnode(l,pos-1,v));
	return odt.insert(odtnode(pos,r,v)).first;
}

// Assign to same value
inline void assign(int l,int r,ll k){
	IT itr=split(r+1),itl=split(l);
	odt.erase(itl,itr);
	odt.insert(odtnode(l,r,k));
}

// [l,r] + k
inline void add(int l,int r,ll k){
	IT itr=split(r+1),itl=split(l);
	for(;itl!=itr;itl++) itl->v+=k;
}

// kth small
inline ll kths(int l,int r,int k){
	IT itr=split(r+1),itl=split(l);
	vector<pair<ll,int>> vec;
	vec.clear();
	for(;itl!=itr;itl++){
		vec.push_back(pair<ll,int>(itl->v,itl->r-itl->l+1));
	}
	sort(vec.begin(),vec.end());
	for(vector<pair<ll,int>>::iterator it=vec.begin();it!=vec.end();it++){
		k-=it->second;
		if(k<=0) return it->first;
	}
	return -1ll;
}

// x pow sum mod y
inline ll xpowsum(int l,int r,ll x,ll y){
	IT itr=split(r+1),itl=split(l);
	ll res=0;
	for(;itl!=itr;itl++){
		res=((res+(itl->r-itl->l+1)*qpow(itl->v,x,y)%y)%y+y)%y;
	}
	return res;
}

int main(){
	scanf("%d%d%lld%d",&n,&m,&seed,&vmax);
	rep(i,1,n) odt.insert(odtnode(i,i,rnd()%vmax+1));
	
	rep(i,1,m){
		ll x,y;
		int op=(rnd()%4)+1;
		int l=(rnd()%n)+1;
		int r=(rnd()%n)+1;
		if(l>r) swap(l,r);
		if(op==3) x=(rnd()%(r-l+1))+1;
		else x=(rnd()%vmax)+1;
		if(op==4) y=(rnd()%vmax)+1;
		if(op==1) add(l,r,x);
		if(op==2) assign(l,r,x);
		if(op==3) printf("%lld\n",kths(l,r,x));
		if(op==4) printf("%lld\n",xpowsum(l,r,x,y));
	}
	return 0;
}