#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int n,a[N],l,r,c,op;
int blk,bel[N],st[N],en[N],sz[N],ptg[N],sum[N];
inline void init_blk(){
	blk=sqrt(n);
	for(int i=1;i<=blk;i++){
		st[i]=n/blk*(i-1)+1;
		en[i]=n/blk*i;
	}
	en[blk]=n;
	for(int i=1;i<=blk;i++){
		sz[i]=en[i]-st[i]+1;
		for(int j=st[i];j<=en[i];j++){
			bel[j]=i;
			sum[i]+=a[j];
		}
	}
}

inline void add(int l,int r,int c){
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++){
			a[i]+=c;
			sum[bel[i]]+=c;
		}
	}else{
		for(int i=l;i<=en[bel[l]];i++){
			a[i]+=c;
			sum[bel[i]]+=c;
		}
		for(int i=st[bel[r]];i<=r;i++){
			a[i]+=c;
			sum[bel[i]]+=c;
		}
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			ptg[i]+=c;
		}
	}
}

inline int getval(int l,int r,int k){
	int ans=0;
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++){
			ans=(ans+a[i]+ptg[bel[i]])%k;
		}
	}else{
		for(int i=l;i<=en[bel[l]];i++){
			ans=(ans+a[i]+ptg[bel[i]])%k;
		}
		for(int i=st[bel[r]];i<=r;i++){
			ans=(ans+a[i]+ptg[bel[i]])%k;
		}
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			ans=(ans%k+sum[i]%k+ptg[i]%k*sz[i]%k)%k;
		}
	}
	return ans%k;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    init_blk();
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d%d",&op,&l,&r,&c);
    	if(op==0) add(l,r,c);
		else{
			printf("%d\n",getval(l,r,c+1));
		}
	}
    return 0;
}

