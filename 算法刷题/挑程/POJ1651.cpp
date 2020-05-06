#include<iostream>
#include<cstdlib>
using namespace std;
const int inf=1<<30;
int n,dp[405][405],a[405];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int len=3;len<=n;len++){
		for(int j=1,ends=len+j-1;ends<=n;j++,ends=len+j-1){
			dp[j][ends]=inf;
			for(int k=j+1;k<ends;k++){
				dp[j][ends]=min(dp[j][ends],dp[j][k]+dp[k][ends]+a[j]*a[k]*a[ends]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}//https://vjudge.net/problem/POJ-1651
