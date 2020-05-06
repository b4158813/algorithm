#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int n,m,a[500005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	int maxh=-inf;
	for(int i=m;i<=n;i++){
		maxh=max(maxh,a[i]-a[i-m]);
	}
	printf("%d\n",maxh);
	return 0;
}
