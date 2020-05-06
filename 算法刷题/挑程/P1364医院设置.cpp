#include<bits/stdc++.h>
using namespace std;
int dp[105][105],num[105];
int ans=1e9;
int n;
void gao(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]); 
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			else dp[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>num[i];
		int x;
		cin>>x;
		if(x!=0){
			dp[i][x]=1;
			dp[x][i]=1;
		}
		cin>>x;
		if(x!=0){
			dp[i][x]=1;
			dp[x][i]=1;
		}
	}
	gao();
	for(int k=1;k<=n;k++){
		int temp = 0;
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			temp+=dp[k][i]*num[i];
		}
		ans = min(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}//https://www.luogu.com.cn/problem/P1364
