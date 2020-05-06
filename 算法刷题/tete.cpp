#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll R,n,L,T,W,H;
ll S,cha;
struct node{
	ll x1,y1,x2,y2;
}a[100005];
inline ll getS(ll k){
	ll sq=0;
	for(ll i=1;i<=n;i++){
		if(a[i].x1<=k){
			if(a[i].x2<=k){
				sq+=(a[i].x2-a[i].x1)*(a[i].y1-a[i].y2);
			}else{
				sq+=(k-a[i].x1)*(a[i].y1-a[i].y2);
			}
		}
	}
	return sq;
}
int main() {
    scanf("%lld",&R);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
    	scanf("%lld%lld%lld%lld",&L,&T,&W,&H);
    	a[i].x1=L,a[i].y1=T,a[i].x2=L+W,a[i].y2=T-H;
    	S+=W*H;
	}
//	printf("S=%lld\n",S);
	ll l=0,r=R;
	ll ans1=0,ans2=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		ll sq=getS(mid);
//		printf("sq=%lld,mid=%lld\n",sq,mid);
		if(2*sq<S) l=mid+1;
		else r=mid-1,ans1=mid,cha=2*sq-S;
	}
	
	l=0,r=R;
	while(l<=r){
		ll mid=(l+r)>>1;
		ll sq=getS(mid);
		printf("sq=%lld,l=%lld,r=%lld,mid=%lld\n",sq,l,r,mid);
		if(2*sq>S) r=mid-1;
		else l=mid+1,ans2=mid;
	}
	
	printf("ans1=%lld\nans2=%lld\n",ans1,ans2);
    return 0;
}
