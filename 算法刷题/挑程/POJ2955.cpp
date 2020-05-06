#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
string s;
int dp[105][105];
int main(){
	while(cin>>s&&s!="end"){
		memset(dp,0,sizeof(dp));
		int len=s.length();
		for(int i=1;i<=len;i++){
			for(int j=0,ends=j+i-1;ends<len;j++,ends=j+i-1){
				if((s[ends]==')'&&s[j]=='(')||(s[ends]==']'&&s[j]=='[')){
					dp[j][ends]=dp[j+1][ends-1]+2;
				}
				for(int k=j;k<ends;k++){
					dp[j][ends]=max(dp[j][ends],dp[j][k]+dp[k][ends]);
				} 
			}	
		}
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
} //https://vjudge.net/problem/POJ-2955
