#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b[1005],c[1005],cc[1005][1005],dp[1005];
int main(){
	cin>>m>>n;
	int maxx=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>a[i]>>b[i]>>x;
		c[x]++;
		cc[x][c[x]]=i;
		maxx=max(maxx,x);
	}
	for(int i=1;i<=maxx;i++){
		for(int j=m;j>=0;j--){
			for(int k=1;k<=c[i];k++){
				if(j>=a[cc[i][k]]) 
					dp[j]=max(dp[j],dp[j-a[cc[i][k]]]+b[cc[i][k]]);
			}
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
