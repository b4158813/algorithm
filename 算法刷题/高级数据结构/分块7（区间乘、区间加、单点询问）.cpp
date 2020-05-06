#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e4+7;
int n,a[N],l,r,c,op;
int blk,bel[N],st[N],en[N],sz[N],ptg[N],mtg[N];
inline void init_blk(){
	blk=sqrt(n);
	for(int i=1;i<=blk;i++){
		st[i]=n/blk*(i-1)+1;
		en[i]=n/blk*i;
	}
	en[blk]=n;
	for(int i=1;i<=blk;i++){
		mtg[i]=1;
		sz[i]=en[i]-st[i]+1;
		for(int j=st[i];j<=en[i];j++){
			a[j]%=mod;
			bel[j]=i;
		}
	}
}

inline void giao(int x){//将标记展开赋值并重置 
	for(int i=st[x];i<=en[x];i++){
		a[i]=(a[i]*mtg[x]+ptg[x])%mod;
	}
	mtg[x]=1,ptg[x]=0;
}

inline void add(int l,int r,int c){
	if(bel[l]==bel[r]){
		giao(bel[l]);
		for(int i=l;i<=r;i++){
			a[i]=(a[i]+c)%mod;
		}
	}else{
		giao(bel[l]);
		for(int i=l;i<=en[bel[l]];i++){
			a[i]=(a[i]+c)%mod;
		}
		giao(bel[r]);
		for(int i=st[bel[r]];i<=r;i++){
			a[i]=(a[i]+c)%mod;
		}
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			ptg[i]=(ptg[i]+c)%mod;
		}
	}
}

inline void mul(int l,int r,int c){
	if(bel[l]==bel[r]){
		giao(bel[l]);
		for(int i=l;i<=r;i++){
			a[i]=(a[i]*c)%mod;
		}
	}else{
		giao(bel[l]); 
		for(int i=l;i<=en[bel[l]];i++){
			a[i]=(a[i]*c)%mod;
		}
		giao(bel[r]);
		for(int i=st[bel[r]];i<=r;i++){
			a[i]=(a[i]*c)%mod;
		}
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			mtg[i]=(mtg[i]*c)%mod;
			ptg[i]=(ptg[i]*c)%mod;
		}
	}
}

inline int getval(int x){
	return (a[x]*mtg[bel[x]]%mod+ptg[bel[x]]%mod)%mod;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    init_blk();
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d%d",&op,&l,&r,&c);
    	if(op==0) add(l,r,c);
    	if(op==1) mul(l,r,c);
		if(op==2){
			printf("%d\n",getval(r));
		}
	}
    return 0;
}
