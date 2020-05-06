#include<cstdio>
using namespace std;
int n,m,a[500005],c[500005];
inline int lowbit(int x){
	return x&-x;
}
inline void update(int i,int k){
	while(i<=n) c[i]+=k,i+=lowbit(i);
}
inline int getsum(int i){
	int res=0;
	while(i>0) res+=c[i],i-=lowbit(i);
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		update(i,a[i]-a[i-1]);
	}
	int op,x,y,k;
	for(int i=1;i<=m;i++){
		scanf("%d",&op);
		if(op==1) scanf("%d%d%d",&x,&y,&k),update(x,k),update(y+1,-k);
		else scanf("%d",&x),printf("%d\n",getsum(x));
	}
	return 0;
}
