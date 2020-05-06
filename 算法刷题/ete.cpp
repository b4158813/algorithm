#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005];

inline bool check(int k,int x,int y){
	if(x*1.0/a[k]+y*1.0/b[k]<1) return true;
	return false;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
    	int x,y;
    	scanf("%d%d",&x,&y);
    	int l=0,r=n,ans=0;
    	while(l<=r){
    		int mid=(l+r)>>1;
    		if(check(mid,x,y)) r=mid-1;
    		else l=mid+1,ans=mid;
		}
		printf("%d\n",ans);
	}
    return 0;
}

