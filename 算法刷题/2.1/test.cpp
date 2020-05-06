#include<bits/stdc++.h>
using namespace std;
int countt;
int dp[1005];

int fac(int x){
	if(x==1||x==0) return 1;
	if(dp[x]) return dp[x];
	return dp[x]=x*fac(x-1);
}

int  C(int m,int k)
 {   
    int ans = fac(m)/(fac(k)*fac(m-k));
 }
 
 int main(){
 	countt=0;
 	cout<<C(6,2);
 }
