#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,ins,tot,cnt=1,a[N],op,l,r,c;
int blk,bel[N],st[N],en[N],sz[N],ptg[N];
vector<int> vec[N];
vector<int>::iterator it;

inline void reset(){
	tot=0;
	for(int i=1;i<=blk;i++){
		for(int j=0;j<vec[i].size();j++){
			a[++tot]=vec[i][j];
		}
	}
	blk=sqrt(tot);
	for(int i=1;i<=blk;i++){
		st[i]=(tot)/blk*(i-1)+1;
		en[i]=(tot)/blk*i;
	}
	en[blk]=tot;
	for(int i=1;i<=blk;i++){
		vec[i].clear();
		sz[i]=en[i]-st[i]+1;
		for(int j=st[i];j<=en[i];j++){
			vec[i].push_back(a[j]);
			bel[j]=i;
		}
	}
}

inline void init_blk(){
	blk=sqrt(n);
	for(int i=1;i<=blk;i++){
		st[i]=(n)/blk*(i-1)+1;
		en[i]=(n)/blk*i;
	}
	en[blk]=n;
	for(int i=1;i<=blk;i++){
		vec[i].clear();
		sz[i]=en[i]-st[i]+1;
		for(int j=st[i];j<=en[i];j++){
			vec[i].push_back(a[j]);
			bel[j]=i;
		}
	}
}

inline void Insert(int x,int k){
	int s=0,p;
	for(int i=1;i<=bel[x];i++){
		s+=sz[i];
		if(s>=x){
			s-=sz[i];
			p=i;
			break;
		}
	}
	sz[p]++;
	int pos=x-s;
	it=vec[p].begin();
	for(int i=1;i<=pos-1;i++) it++;
	vec[p].insert(it,k);
}

inline int getval(int x){
	int s=0,p;
	for(int i=1;i<=bel[x];i++){
		s+=sz[i];
		if(s>=x){
			s-=sz[i];
			p=i;
			break;
		}
	}
	int pos=x-s;
	it=vec[p].begin();
	for(int i=1;i<=pos-1;i++) it++;
	return *it;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    init_blk();
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d%d",&op,&l,&r,&c);
    	if(op==0){
    		Insert(l,r);
    		if(++ins>=cnt*sqrt(n)){
    			reset();
    			cnt++;
			}
		}else{
			printf("%d\n",getval(r));
		}
	}
    return 0;
}

