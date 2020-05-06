#include<cstdio>
using namespace std;
typedef long long ll;
int n,m;
ll a[500005],c1[500005],c2[500005];
inline int lowbit(int x){
	return x&-x;
}
inline void update(int i,int k){
	int x=i;
	while(i<=n) c1[i]+=k,c2[i]+=k*(x-1),i+=lowbit(i);
}
inline ll getsum(int i){
	ll res=0,x=i;
	while(i>0) res+=x*c1[i]-c2[i],i-=lowbit(i);
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
		else scanf("%d%d",&x,&y),printf("%lld\n",getsum(y)-getsum(x-1));
	}
	return 0;
}
