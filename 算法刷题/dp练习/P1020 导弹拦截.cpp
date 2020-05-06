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
const int maxn = 100105;
int a[maxn],n;
int dp2[maxn],dp1[maxn],len1,len2;
int main() {
	int x;
//	freopen("P1020_3.in","r",stdin);
    while(cin>>x){
    	a[++n]=x;
	}
	for(int i=1;i<=n;i++){
		if(dp2[len2]<a[i]) dp2[++len2]=a[i];
		else{
			int pos=lower_bound(dp2+1,dp2+1+len2,a[i])-dp2;
			dp2[pos]=a[i];
		}
		if(len1==0||dp1[len1]>=a[i]) dp1[++len1]=a[i];
		else{
			int pos=upper_bound(dp1+1,dp1+1+len1,a[i],greater<int>())-dp1;
			dp1[pos]=a[i];
		}
	}
	printf("%d\n%d\n",len1,len2);
    return 0;
}

