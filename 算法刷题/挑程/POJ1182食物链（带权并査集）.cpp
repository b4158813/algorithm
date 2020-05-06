#include<iostream>
#include<cstdio>
using namespace std;
int par[500005];
int rank[500005];

void init(int n){ //初始化并査集 
	for(int i=0;i<n;i++){
		par[i]=i;
		rank[i]=0;
	}
}

int find(int x){ //查询x在哪个组里 
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y){ //合并x和y所在的组 
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rank[x]<rank[y]) par[x]=y;
	else{
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}

bool same(int x, int y){ //判断x和y是否在同一组 
	return find(x)==find(y);
}


int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	init(3*n);
	int ans=0;
	for(int i=1;i<=k;i++){
		int x,a,b;
		scanf("%d %d %d",&x,&a,&b);
		a=a-1,b=b-1;
		if(a>=n||b>=n){
			ans++;
			continue;
		}
		if(x==1){
			if(same(a,b+n)||same(a,b+2*n)){
				ans++;
				continue;
			}else{
				unite(a,b);
				unite(a+n,b+n);
				unite(a+2*n,b+2*n); 
			}
		}
		if(x==2){
			if(same(a,b)||same(a,b+2*n)){
				ans++;
				continue;
			}else{
				unite(a,b+n);
				unite(a+n,b+2*n);
				unite(a+2*n,b);
			}
		}
	} 
	printf("%d\n",ans);
	return 0;
}
