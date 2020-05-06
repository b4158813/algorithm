#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
char mm[105][35];
int dp[105][70][70];
int sta[70],cnt;
int num[300];
inline bool ok(int x){
	if(!((x&x<<1)||(x&x>>1)||(x&x<<2)||(x&x>>2))) return true;
	return false;
}

inline int getnum(int x){
	int ans=0;
	while(x){
		ans++;
		x-=(x&(-x));
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mm[i][j];
			if(mm[i][j]=='H') a[i]|=1<<m-j;
		}
//		cout<<a[i]<<endl;
	}
	
	for(int i=0;i<1<<m;i++){
		if(ok(i)){
//			cout<<i<<endl;
			sta[++cnt]=i;
			num[cnt]=getnum(i);
		}
	}
//	cout<<cnt<<endl;
	
	for(int i=1;i<=cnt;i++){
		if((sta[i]&a[1])==0){
			dp[1][i][0]=num[i];
//			cout<<dp[1][i][0]<<endl;
		}
	}
//	exit(0);
	for(int i=1;i<=cnt;i++){
		if((sta[i]&a[2])==0){
			for(int j=1;j<=cnt;j++){
				if((sta[j]&a[1])==0&&(sta[j]&sta[i])==0){
					dp[2][i][j]=num[i]+num[j];
				}
			}
		}
	}
//	exit(0);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			if((sta[j]&a[i])==0){
				for(int k=1;k<=cnt;k++){
					if((sta[j]&sta[k])==0&&(sta[k]&a[i-1])==0){
						for(int l=1;l<=cnt;l++){
							if((sta[l]&sta[j])==0&&(sta[l]&sta[k])==0&&(sta[l]&a[i-2])==0){
								dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+num[j]);
							}
						}
					} 
				}
			}
		}
	}
//	exit(0);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			ans=max(ans,dp[n][i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
} //https://www.luogu.com.cn/problem/P2704
