#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,maxh;
int a[20005],c[50005];
ll ans[20005];
inline int lowbit(int i){
	return i&-i;
}
inline void update(int i){
	while(i<=maxh) c[i]++,i+=lowbit(i);
}
inline ll getsum(int i){
	ll res=0;
	while(i) res+=c[i],i-=lowbit(i);
	return res;
}
int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&x),a[i]++,maxh=max(maxh,a[i]);
	for(int i=1;i<=n;i++){
		ans[getsum(a[i])]++;
//		printf("%d level:%d\n",a[i],getsum(a[i]));
		update(a[i]);
	}
	for(int i=0;i<n;i++) printf("%lld\n",ans[i]);
	return 0;
}
