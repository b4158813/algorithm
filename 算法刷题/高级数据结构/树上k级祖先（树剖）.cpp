#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
const int maxn=5e5+5;
typedef long long ll;
inline ll read() {//快读
	ll kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}

inline void write(ll x){//快写
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}
#define ui unsigned int
ui s;

inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}

int n,q,f[maxn];
int cnt,head[maxn];
struct Edge
{
	int u,v,next;
}e[maxn<<1];
inline void addedge(int u,int v){
	e[cnt]=Edge{u,v,head[u]};
	head[u]=cnt++;
}

int csfa[maxn],csid[maxn],csson[maxn],csdep[maxn],csmx[maxn],cstop[maxn];
int csdfn,csw[maxn];

inline void dfs1(int u,int fath,int depth){
	csdep[u]=depth;
	csfa[u]=fath;
	csmx[u]=csdep[u];
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=fath){
			dfs1(v,u,depth+1);
			csmx[u]=max(csmx[u],csmx[v]);
			if(csmx[v]>csmx[csson[u]])
				csson[u]=v;
		}
	}
}

inline void dfs2(int u,int topf){
	csid[u]=++csdfn;
	csw[csdfn]=u;
	cstop[u]=topf;
	if(!csson[u]) return;
	dfs2(csson[u],topf);
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(v!=csfa[u]&&v!=csson[u]){
			dfs2(v,v);
		}
	}
}

inline int getval(int x,int k){
	int tp=csdep[x]-k;
	while(csdep[cstop[x]]>tp) x=csfa[cstop[x]];
	tp=csdep[x]-tp;;
	return csw[csid[x]-tp];
}

int main(){
	n=read(),q=read();
	scanf("%u",&s);
	memset(head,-1,sizeof(head));
	int rt,x;
	rep(i,1,n){
		x=read();
		if(!x) rt=i;
		else addedge(i,x),addedge(x,i);
	}
	dfs1(rt,-1,1);
	dfs2(rt,rt);
	ll Ans=0,ans=0;
	rep(i,1,q){
		int x=((get(s)^ans)%n)+1;
		int k=(get(s)^ans)%csdep[x];
		ans=getval(x,k);
		Ans^=(ll)i*ans;
	}
	write(Ans),putchar('\n');
	return 0;
}//https://www.luogu.com.cn/problem/P5903