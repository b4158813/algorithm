#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	int ans=0;
	int lcm=x*y;
	for(int i=1;i<=1000000;i++){
		if(lcm%i==0&&__gcd(lcm/i,i)==x) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
