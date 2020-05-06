#include<bits/stdc++.h>
using namespace std;

long long ans;
long long mo[9]={1,11,111,1111,11111,111111,1111111,11111111,111111111};
int main(){
	int t;
	cin>>t;
	while(t--){
		long long v;
		ans=0;
		cin>>v;
		for(int i=8;i>=0;i--){
			ans+=v/mo[i];
			v%=mo[i];
		}
		if(ans<=9) cout<<ans<<endl;
		else cout<<"Impossible"<<endl;
	}
	return 0;
}
