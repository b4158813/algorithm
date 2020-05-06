#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ap=(n&1)?a[n/2+1]:(a[n/2]+a[n/2+1])/2;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=abs(ap-a[i]);
	}
	printf("%lld\n",ans);
    return 0;
}

