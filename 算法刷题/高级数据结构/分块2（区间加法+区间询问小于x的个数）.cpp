#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int n,a[N],op,l,r,c;
int blk,bel[N],st[N],en[N],sz[N],ptg[N];
vector<int> vec[N];
inline void Sort(int x){
	for(int i=0;i<sz[x];i++){
		vec[x][i]=a[st[x]+i];
	}
	sort(vec[x].begin(),vec[x].end());
}
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
			vec[i].push_back(a[j]);
			bel[j]=i;
		}
		sort(vec[i].begin(),vec[i].end());
	}
}

inline void add(int l,int r,int c){
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++){
			a[i]+=c;
		}
		Sort(bel[l]);
	}else{
		for(int i=l;i<=en[bel[l]];i++){
			a[i]+=c;
		}
		Sort(bel[l]);
		for(int i=st[bel[r]];i<=r;i++){
			a[i]+=c;
		}
		Sort(bel[r]);
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			ptg[i]+=c;
		}
	}
}

inline int getval(int l,int r,int k){
	int ans=0;
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++){
			if(a[i]<k-ptg[bel[i]]) ans++;
		}
	}else{
		for(int i=l;i<=en[bel[l]];i++){
			if(a[i]<k-ptg[bel[i]]) ans++;
		}
		for(int i=st[bel[r]];i<=r;i++){
			if(a[i]<k-ptg[bel[i]]) ans++;
		}
		for(int i=bel[l]+1;i<=bel[r]-1;i++){
			int pos=lower_bound(vec[i].begin(),vec[i].end(),k-ptg[i])-vec[i].begin();
			ans+=pos;
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
    	if(op==0) add(l,r,c);
		else{
			printf("%d\n",getval(l,r,c*c));
		}
	}
    return 0;
}

