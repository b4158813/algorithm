#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main(){
	string a,b;
	while(cin>>a>>b){
		memset(dp,0,sizeof(dp));
		int lena = a.length();
		int lenb = b.length();
		for(int i=0;i<lena;i++){
			for(int j=0;j<lenb;j++){
				if(a[i]==b[j]) dp[i+1][j+1] = dp[i][j]+1;
				else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
		cout<<lena+lenb-dp[lena][lenb]<<endl;
	}
	return 0;
}
