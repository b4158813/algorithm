#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,l,r,c,a[N];
int st[N],en[N],blk,bel[N],sz[N],tg[N];
inline void init_blk(){
	blk=sqrt(n);
	memset(tg,-1,sizeof(tg));
	for(int i=1;i<=blk;i++){
		st[i]=n/blk*(i-1)+1;
		en[i]=n/blk*i;
	}
	en[blk]=n;
	for(int i=1;i<=blk;i++){
		sz[i]=en[i]-st[i]+1;
		for(int j=st[i];j<=en[i];j++){
			bel[j]=i;
		}
	}
}

inline void giao(int x){
	if(tg[x]==-1) return;
	for(int i=st[x];i<=en[x];i++){
		a[i]=tg[x];
	}
	tg[x]=-1;
	return;
}

inline int search(int l,int r,int c){
	int ans=0;
	if(bel[l]==bel[r]){
		giao(bel[l]);
		for(int i=l;i<=r;i++){
			if(a[i]==c) ans++;
			else a[i]=c;
		}
	}else{
		giao(bel[l]);
		for(int i=l;i<=en[bel[l]];i++){
			if(a[i]==c) ans++;
			else a[i]=c;
		}
		giao(bel[r]);
		for(int i=st[bel[r]];i<=r;i++){
			if(a[i]==c) ans++;
			else a[i]=c;
		}
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			if(tg[i]!=-1){
				if(tg[i]==c) ans+=sz[i];
			}else{
				for(int j=st[i];j<=en[i];j++){
					if(a[j]==c) ans++;
					else a[j]=c;
				}
			}
			tg[i]=c;
		}
	}
	return ans;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    init_blk();
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d",&l,&r,&c);
    	printf("%d\n",search(l,r,c));
	}
    return 0;
}

