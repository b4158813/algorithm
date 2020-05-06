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
const int maxn=600005;
ll qpow(ll x,ll y,ll Mod) {ll ans=1,base=x%Mod; while(y){if(y&1)ans=(ans*base)%Mod;base=(base*base)%Mod;y>>=1;} return ans;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

int n,m;

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
	k%=mod;
	IT itr=split(r+1),itl=split(l);
	odt.erase(itl,itr);
	odt.insert(odtnode(l,r,k));
}

// [l,r] + k
inline void add(int l,int r,ll k){
	k%=mod;
	IT itr=split(r+1),itl=split(l);
	for(;itl!=itr;itl++) itl->v=(itl->v+k)%mod;
}

//区间求和
inline ll getsum(int l,int r){
	IT itr=split(r+1),itl=split(l);
	ll res=0;
	for(;itl!=itr;itl++){
		res=((res+itl->v*(itl->r-itl->l+1)%mod)%mod+mod)%mod;
	}
	return res%mod;
}

// 区间拷贝
inline void copy(int l1,int r1,int l2,int r2){
	IT itr1=split(r1+1),itl1=split(l1);
	vector<pair<ll,int>> vec;
	for(IT it=itl1;it!=itr1;it++){
		vec.pb(pair<ll,int>(it->v,it->r-it->l+1));
	}

	IT itr2=split(r2+1),itl2=split(l2);
	odt.erase(itl2,itr2);

	for(vector<pair<ll,int>>::iterator it=vec.begin();it!=vec.end();it++){
		odt.insert(odtnode(l2,l2+it->second-1,it->first));
		l2+=it->second;
	}
}

// 区间交换
inline void exchange(int l1,int r1,int l2,int r2){
	if(l1>l2) swap(l1,l2),swap(r1,r2);
	
	IT itr1=split(r1+1),itl1=split(l1);
	vector<pair<ll,int>> vec1,vec2;
	for(IT it=itl1;it!=itr1;it++){
		vec1.pb(pair<ll,int>(it->v,it->r-it->l+1));
	}
	odt.erase(itl1,itr1);

	IT itr2=split(r2+1),itl2=split(l2);
	for(IT it=itl2;it!=itr2;it++){
		vec2.pb(pair<ll,int>(it->v,it->r-it->l+1));
	}
	odt.erase(itl2,itr2);

	for(vector<pair<ll,int>>::iterator it=vec1.begin();it!=vec1.end();it++){
		odt.insert(odtnode(l2,l2+it->second-1,it->first));
		l2+=it->second;
	}
	for(vector<pair<ll,int>>::iterator it=vec2.begin();it!=vec2.end();it++){
		odt.insert(odtnode(l1,l1+it->second-1,it->first));
		l1+=it->second;
	}
}

// 区间翻转
inline void updown(int l,int r){
	if(l>r) swap(l,r);
	IT itr=split(r+1),itl=split(l);
	vector<pair<ll,int>> vec;
	for(IT it=itl;it!=itr;it++){
		vec.pb(pair<ll,int>(it->v,it->r-it->l+1));
	}
	odt.erase(itl,itr);
	reverse(All(vec));
	for(vector<pair<ll,int>>::iterator it=vec.begin();it!=vec.end();it++){
		odt.insert(odtnode(l,l+it->second-1,it->first));
		l+=it->second;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int x;
	rep(i,1,n) scanf("%d",&x),odt.insert(odtnode(i,i,x));
	int op,l1,r1,l2,r2,val;
	while(m--){
		scanf("%d%d%d",&op,&l1,&r1);
		if(op==1) printf("%lld\n",getsum(l1,r1));
		if(op==2) scanf("%d",&val),assign(l1,r1,1ll*val);
		if(op==3) scanf("%d",&val),add(l1,r1,1ll*val);
		if(op==4) scanf("%d%d",&l2,&r2),copy(l1,r1,l2,r2);
		if(op==5) scanf("%d%d",&l2,&r2),exchange(l1,r1,l2,r2);
		if(op==6) updown(l1,r1);
	}
	IT itr=split(n+1),itl=split(1);
	for(IT it=itl;it!=itr;it++){
		rep(i,1,it->r-it->l+1){
			printf("%lld ",it->v%mod);
		}
	}
	return 0;
}