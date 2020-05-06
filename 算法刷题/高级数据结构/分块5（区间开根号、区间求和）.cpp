#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int n,a[N],l,r,c,op;
int blk,bel[N],st[N],en[N],sz[N],ptg[N],sum[N],mx[N];
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
			mx[i]=max(mx[i],a[j]);
		}
	}
}

inline void Sqrt(int l,int r){
	if(bel[l]==bel[r]){
		if(mx[bel[l]]<=1) return;
		for(int i=l;i<=r;i++){
			a[i]=sqrt(a[i]);
		}
		mx[bel[l]]=sum[bel[l]]=0;
		for(int i=st[bel[l]];i<=en[bel[l]];i++){
			mx[bel[i]]=max(mx[bel[i]],a[i]);
			sum[bel[i]]+=a[i];
		}
	}else{
		for(int i=l;i<=en[bel[l]];i++){
			a[i]=sqrt(a[i]);
		}
		mx[bel[l]]=sum[bel[l]]=0;
		for(int i=st[bel[l]];i<=en[bel[l]];i++){
			mx[bel[i]]=max(mx[bel[i]],a[i]);
			sum[bel[i]]+=a[i];
		}
		for(int i=st[bel[r]];i<=r;i++){
			a[i]=sqrt(a[i]);
		}
		mx[bel[r]]=sum[bel[r]]=0;
		for(int i=st[bel[r]];i<=en[bel[r]];i++){
			mx[bel[i]]=max(mx[bel[i]],a[i]);
			sum[bel[i]]+=a[i];
		}
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			if(mx[i]<=1) continue;
			mx[i]=sum[i]=0;
			for(int j=st[i];j<=en[i];j++){
				a[j]=sqrt(a[j]);
				mx[i]=max(mx[i],a[j]);
				sum[i]+=a[j];
			}
		}
	}
}

inline int getsum(int l,int r){
	int ans=0;
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++){
			ans=ans+a[i]+ptg[bel[i]];
		}
	}else{
		for(int i=l;i<=en[bel[l]];i++){
			ans=ans+a[i]+ptg[bel[i]];
		}
		for(int i=st[bel[r]];i<=r;i++){
			ans=ans+a[i]+ptg[bel[i]]; 
		}
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			ans=ans+sum[i]+ptg[i]*sz[i];
		}
	}
	return ans;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    init_blk();
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d%d",&op,&l,&r,&c);
    	if(op==0) Sqrt(l,r);
		else{
			printf("%d\n",getsum(l,r));
		}
	}
    return 0;
}

