#include<bits/stdc++.h>
using namespace std;
int dp[1005];
int fac(int x){
	if(x==1||x==0) return 1;
	if(dp[x]) return dp[x];
	return dp[x]=x*fac(x-1);
}

int  C(int m,int k){
	int ans = fac(m)/(fac(k)*fac(m-k));
	return ans;
}
double ans;
int main(){
	int n,r,s,x,y,w;
	cin>>n;
	while(n--){
		ans=0;
		cin>>r>>s>>x>>y>>w;
		double py = 1.0*(s-r+1)/s;
		double ppp=1.0-py;
		for(int i=x;i<=y;i++){
			double temp_ps = 1.0;
			double temp_py = 1.0;
			int cnt = y-i;
			while(cnt--) temp_ps*=ppp;
			for(int j=1;j<=i;j++) temp_py*=py;
			ans+=C(y,i)*temp_ps*temp_py;
		}
		if(ans*w>1) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
