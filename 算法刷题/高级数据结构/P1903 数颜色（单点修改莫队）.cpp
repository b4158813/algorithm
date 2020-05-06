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
const int maxn=150005;
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

int n,m,st[maxn],en[maxn],blk,bel[maxn],cnt[maxn*8],a[maxn];
int qcnt,mcnt;
int l,r,tim,ans,Ans[maxn];
struct que
{
	int l,r,id,tim;
}q[maxn];
struct modi
{
	int pos,val;
}md[maxn];
bool cmp(que x1,que x2){
	if(bel[x1.l]==bel[x2.l]&&bel[x1.r]==bel[x2.r]) return x1.tim<x2.tim;
	if(bel[x1.l]==bel[x2.l]) return bel[x1.r]<bel[x2.r];
	return bel[x1.l]<bel[x2.l];
}
inline void init_blk(){
	blk=pow(n,1.0/3.0);
	rep(i,1,blk) st[i]=n/blk*(i-1)+1,en[i]=n/blk*i;
	en[blk]=n;
	rep(i,1,blk)
		rep(j,st[i],en[i])
			bel[j]=i;
}
inline void add(int pos){
	if(!cnt[a[pos]]) ++ans;
	++cnt[a[pos]];
}
inline void del(int pos){
	--cnt[a[pos]];
	if(!cnt[a[pos]]) --ans;
}
int main(){
	n=read(),m=read();
	rep(i,1,n) a[i]=read();
	init_blk();
	rep(i,1,m){
		char c[2];
		int l,r;
		scanf("%s",c);
		l=read(),r=read();
		if(c[0]=='Q'){
			q[++qcnt].l=l;
			q[qcnt].r=r;
			q[qcnt].id=qcnt;
			q[qcnt].tim=mcnt;
		}else{
			md[++mcnt].pos=l;
			md[mcnt].val=r;
		}
	}
	sort(q+1,q+1+qcnt,cmp);

	rep(i,1,m){
		int tl=q[i].l,tr=q[i].r,tt=q[i].tim;
		while(l<tl) del(l++);
		while(l>tl) add(--l);
		while(r<tr) add(++r);
		while(r>tr) del(r--);
		while(tt>tim){
			++tim;
			if(md[tim].pos>=tl&&md[tim].pos<=tr){
				if(!cnt[md[tim].val]) ans++;
				++cnt[md[tim].val];
				--cnt[a[md[tim].pos]];
				if(!cnt[a[md[tim].pos]]) ans--;
			}
			swap(a[md[tim].pos],md[tim].val);
		}
		while(tt<tim){
			if(md[tim].pos>=tl&&md[tim].pos<=tr){
				if(!cnt[md[tim].val]) ans++;
				++cnt[md[tim].val];
				--cnt[a[md[tim].pos]];
				if(!cnt[a[md[tim].pos]]) ans--;
			}
			swap(a[md[tim].pos],md[tim].val);
			--tim;
		}
		Ans[q[i].id]=ans;
	}
	rep(i,1,qcnt) write(Ans[i]),putchar('\n');
	return 0;
}