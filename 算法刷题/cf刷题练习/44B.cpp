#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,a,b,c;
int ans;

int main() {
    scanf("%d%d%d%d",&n,&a,&b,&c);
    int d=a/2;
//    printf("%d %d %d %d\n",d,b,c,n);
    for(int i=0;i<=c&&n-2*i>=0;i++){
    	int res=n-2*i;
    	if(d+b<res) continue;
    	for(int j=0;j<=b;j++){
    		int rr=res-j;
//    		printf("rr:%d\n",rr);
    		if(rr<=d&&rr>=0) ans++;
		}
	}
	printf("%d\n",ans);
    return 0;
}

