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
const int maxn = 10000;
int n,m;
struct node{
	int x,y;
}a[205];
bool cmp(node x1,node x2){
	return x1.x<x2.x;
}
int cha,dp[205][205];
int main(){
    scanf("%d%d",&n,&m);
    m=n-m;
    for(int i=1;i<=n;i++){
    	scanf("%d%d",&a[i].x,&a[i].y);
	}
	memset(dp,1,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][1]=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			for(int k=1;k<i;k++){
				dp[i][j]=min(dp[i][j],dp[k][j-1]+abs(a[i].y-a[k].y));
			}
		}
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[i][m]);
	}
	printf("%d\n",ans);
    return 0;
}

