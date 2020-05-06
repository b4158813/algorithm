#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10015;
int a1,a2,b1,b2,n,a[maxn],b[maxn],p[maxn];
int dp[maxn/10];
int main() {
    scanf("%d:%d %d:%d %d",&a1,&b1,&a2,&b2,&n);
    if(a2<a1) a2+=24;
	int ti=(a2-a1)*60+(b2-b1);
//	cout<<ti<<endl;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&p[i]);
	for(int i=1;i<=n;i++){
		if(p[i]==0){
			for(int j=a[i];j<=ti;j++){
				dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
			}
		}else{
			for(int j=ti;j>=0;j--){
				for(int k=1;k<=p[i];k++){
					if(j>=k*a[i]) dp[j]=max(dp[j],dp[j-k*a[i]]+k*b[i]);
				} 
			}
		}
	}
	printf("%d\n",dp[ti]);
    return 0;
}

