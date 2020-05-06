#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][105];
ll n,m;
ll ans[105][105];
ll anss=1e9;

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
					anss = min(anss,dp[i][j]+ans[i][k]+ans[k][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
int main(){
	while(cin>>n>>m){
		anss=1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans[i][j]=dp[i][j]=1e9; 
			}
		}
		while(m--){
			ll x,y,d;
			cin>>x>>y>>d;
			dp[x][y]=dp[y][x]=ans[x][y]=ans[y][x]=min(dp[x][y],d);
		}	
		floyd();
		if(anss==1e9) cout<<"No solution."<<endl;
		else cout<<anss<<endl;
	}
	return 0;
} //https://vijos.org/p/1046
