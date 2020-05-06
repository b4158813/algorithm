#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m){
		if(n%(m+1)==0) cout<<"Wildhunte"<<endl;
		else cout<<"Gerlot"<<endl;
	}
	return 0;
} 
