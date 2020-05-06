#include<bits/stdc++.h>
using namespace std;
int cnt,f[1000005];
int main(){
	int n;
	cin>>n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			++cnt;
			f[cnt]=i;
		}
		while(n%i==0) n/=i;
	}
	if(n!=1){
		++cnt;
		f[cnt]=n;
	}
	cout<<f[cnt]<<endl;
	return 0;
}
