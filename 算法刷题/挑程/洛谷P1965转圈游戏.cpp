#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,x;
inline int qpow(int x,int y){
	int base=x,ans=1;
	while(y>0){
		if(y&1) ans=(ll)ans*base%n;
		base=(ll)base*base%n;
		y>>=1;
	}
	return ans;
}
int main(){
	cin>>n>>m>>k>>x;
	cout<<(x%n+(ll)qpow(10,k)%n*m%n)%n<<endl;
	return 0;
}
