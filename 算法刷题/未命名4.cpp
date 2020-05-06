#include<bits/stdc++.h>
using namespace std;
int dp[9005][9005];
int v[1005];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	int sum=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			for(int k=sum;k>=0;k--){
				if(dp[j][k]){
					dp[j+v[i]][k]=1;
					dp[j][k+v[i]]=1;
				}
			}
		}
		sum+=v[i];
	}
	for(int i=sum;i>0;i--){
		if(dp[i][i]){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}
