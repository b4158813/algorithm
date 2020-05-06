#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int mu=y1*y2/__gcd(y1,y2);
		int z1=x1*(mu/y1),z2=x2*(mu/y2);
		int z=z1+z2;
		int gg=__gcd(mu,z);
		mu/=gg;
		z/=gg;
		cout<<z<<" "<<mu<<endl;
	}
	return 0;
}
