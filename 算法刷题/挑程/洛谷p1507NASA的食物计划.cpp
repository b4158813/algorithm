#include<bits/stdc++.h>
using namespace std;
int v[1005],m[1005],ca[1005];
int dp[1005][1005];
int main(){
	int vol,mass,n;
	cin>>vol>>mass>>n;
	for(int i=1;i<=n;i++) cin>>v[i]>>m[i]>>ca[i];
	for(int i=1;i<=n;i++){
		for(int j=vol;j>=0;j--){
			for(int k=mass;k>=0;k--){
				if(j>=v[i]&&k>=m[i]){
					dp[j][k]=max(dp[j][k],dp[j-v[i]][k-m[i]]+ca[i]);
				}
			}
		}
	}
	cout<<dp[vol][mass]<<endl;
	return 0;
}
