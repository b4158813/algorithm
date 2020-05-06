#include<bits/stdc++.h>
using namespace std;

void fff(string a1,string a2){
	if(a1.size()>0){
		char c = a2[a2.size()-1];
		cout<<c;
		int k=a1.find(c);
		fff(a1.substr(0,k),a2.substr(0,k));
		fff(a1.substr(k+1),a2.substr(k,a1.size()-k-1));
	}
}

int main(){
	string a1,a2;
	cin>>a1>>a2; 
	fff(a1,a2);
	return 0;
}
