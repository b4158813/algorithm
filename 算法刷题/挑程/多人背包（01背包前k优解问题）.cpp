#include<bits/stdc++.h>
using namespace std;

int k,v,n,vo[205],va[205];
int dp[5005][55];
int num[55];

int main(){
	cin>>k>>v>>n;
	for(int i=1;i<=n;i++){
		cin>>vo[i]>>va[i];
	}
	for(int i=0;i<=v;i++){
		for(int j=0;j<=k;j++){
			dp[i][j]=-9999999;
		}
	}
	dp[0][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=v;j>=vo[i];j--){
			int t1=1,t2=1;
			for(int m=1;m<=k;m++){
				if(dp[j][t1]>dp[j-vo[i]][t2]+va[i]){
					num[m]=dp[j][t1];
					t1++;
				}else{
					num[m]=dp[j-vo[i]][t2]+va[i];
					t2++;
				}
			}
			for(int o=1;o<=k;o++){
				dp[j][o]=num[o];
			}
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		if(dp[v][i]<=0) break;
		sum+=dp[v][i];
	}
	cout<<sum<<endl;
	return 0;
}
