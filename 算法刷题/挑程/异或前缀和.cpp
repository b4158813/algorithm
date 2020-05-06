#include<cstdio>
using namespace std;
typedef long long ll;
ll n,m,a[2000005],sum[2000005],xorsum[2000005];
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	xorsum[1]=a[1];
	for(int i=2;i<=n;i++){
		xorsum[i]=xorsum[i-1]^a[i];
	}
	for(int i=1;i<=m;i++){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		printf("%lld\n",x==1?sum[z]-sum[y-1]:xorsum[z]^xorsum[y-1]);
	}
	return 0;
}
