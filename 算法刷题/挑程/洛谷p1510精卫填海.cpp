#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int dp[10005];
int main(){
	int v,n,c;
	scanf("%d%d%d",&v,&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=c;j>=0;j--){
			if(j>=b[i]){
				dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
			}
		}
	}
	for(int i=1;i<=c;i++){
		if(dp[i]>=v){
			cout<<c-i<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}
