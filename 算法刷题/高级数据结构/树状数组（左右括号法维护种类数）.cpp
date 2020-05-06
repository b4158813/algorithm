#include<cstdio>
using namespace std;
int n,m,k,l,r,c1[50005],c2[50005];
inline void update(int c[],int i,int k){
	while(i<=n) c[i]+=k,i+=i&-i;
}
inline int getsum(int c[],int i){
	int res=0;
	while(i>0) res+=c[i],i-=i&-i;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&k,&l,&r);
		if(k==1){
			update(c1,l,1),update(c2,r,1);
		}else{
			printf("%d\n",getsum(c1,r)-getsum(c2,l-1));
		}
	}
	return 0;
}
