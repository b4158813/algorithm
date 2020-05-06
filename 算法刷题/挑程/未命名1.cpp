#include<bits/stdc++.h>
using namespace std;
int main(){
	int  t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ff=0;
		if(n&1){
			ff++;
			cout<<n;
		}
		while(n!=1){
			if(n&1){
				n=n*3+1;
			}else{
				n/=2;
			}
			if(n!=1&&n&1){
				if(ff>=1) cout<<" ";
				cout<<n;
				ff++;
			}
		}
		if(ff==0) cout<<"No number can be output !";
		cout<<endl;
	}
	return 0;
}
