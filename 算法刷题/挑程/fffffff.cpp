#include<bits/stdc++.h>
using namespace std;
int dp[3005][3005];
char s1[3005],s2[3005];
int main(){
	gets(s1+1);
	getchar();
	gets(s2+1);
	int len1=strlen(s1),len2=strlen(s2);
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(s1[i]==s2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				cout<<s1[i];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
}
