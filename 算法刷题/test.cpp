#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
int l,r=1<<30;
inline bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i]/x;
	}
	if(cnt>=k) return true;
	return false;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
    	double temp;
    	scanf("%lf",&temp);
    	a[i]=temp*100;
	}
	double ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid==0) break;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%.2lf\n",ans/100.0);
    return 0;
}

