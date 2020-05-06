#include<cstdio>
using namespace std;
typedef long long ll;
int n,q,a[100005];
ll c1[100005],c2[1000005];
inline void add(int i,int k){
	ll x=1ll*i;
	while(i<=n) c1[i]+=1ll*k,c2[i]+=1ll*k*(x-1),i+=i&-i;
}
inline ll getsum(int i){
	ll res=0,x=i;
	while(i) res+=x*c1[i]-c2[i],i-=i&-i;
	return res;
}
int main() {
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),add(i,a[i]),add(i+1,-a[i]);
	for(int i=1;i<=q;i++){
		char c[2];
		int x,y,z;
		scanf("%s",c);
		if(c[0]=='Q')
			scanf("%d%d",&x,&y),printf("%lld\n",getsum(y)-getsum(x-1));
		else
			scanf("%d%d%d",&x,&y,&z),add(x,z),add(y+1,-z);
	}
    return 0;
}

