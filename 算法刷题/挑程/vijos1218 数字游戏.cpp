#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int dp1[185][185][115],dp2[185][185][115];
int a[155],sum[155];
int n,m;

inline int giao(int x){
	return (x%10+10)%10;
}
int main(){
	cin>>n>>m;
	memset(dp2,0x3f3f3f,sizeof(dp2));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++) sum[i+n]=sum[i+n-1]+a[i];
	
	for(int i=1;i<=2*n;i++){
		for(int j=i;j<=2*n;j++){
			dp1[i][j][1]=dp2[i][j][1]=giao(sum[j]-sum[i-1]);
		} 
	}
	
	for(int i=1;i<=n;i++){
		for(int l=1,r=l+i-1;l<2*n;l++,r=l+i-1){ 
			for(int k=2;k<=m;k++){
				for(int h=l+k-1;h<r;h++){
					dp1[l][r][k]=max(dp1[l][r][k],dp1[l][h][k-1]*giao(sum[r]-sum[h]));
					dp2[l][r][k]=min(dp2[l][r][k],dp2[l][h][k-1]*giao(sum[r]-sum[h]));
				}
			}
		}
	}
	
	int ansmin=inf,ansmax=0;
	for(int i=1;i<=n;i++){
		ansmin=min(ansmin,dp2[i][i+n-1][m]);
		ansmax=max(ansmax,dp1[i][i+n-1][m]);
	}
	
	cout<<ansmin<<endl<<ansmax<<endl;
	return 0;
}// https://www.luogu.com.cn/problem/P1043
