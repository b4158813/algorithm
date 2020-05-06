#include<bits/stdc++.h>
using namespace std;
int n,p;

int main(){
	cin>>n>>p;
	for(int i=0;i<=n-i*p;i++){
		if(i>=__builtin_popcount(n-i*p)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}
