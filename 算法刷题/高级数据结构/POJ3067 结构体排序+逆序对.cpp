#include<cstring>
#include<cstdio>
#include<algorithm> 
using namespace std;
typedef long long ll;
int n,m,k;
ll c[500005];
struct node{
	int x,y;
}a[500005];
bool cmp(node x1,node x2){
	if(x1.x==x2.x) return x1.y<x2.y;
	return x1.x<x2.x;
}
inline void update(int i){
	while(i<=m) c[i]++,i+=i&-i;
}
inline ll getsum(int i){
	ll res=0;
	while(i>0) res+=c[i],i-=i&-i;
	return res;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int o=1;o<=t;o++){
		memset(c,0,sizeof(c));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		sort(a+1,a+1+k,cmp);
		ll ans=0;
		for(int i=1;i<=k;i++){
			update(a[i].y);
			ans+=i-getsum(a[i].y);
		}
		printf("Test case %d: %lld\n",o,ans);
	}
	return 0;
}
