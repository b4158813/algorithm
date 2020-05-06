#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++){
		string s;
		getline(cin,s);
		int len=s.length();
		string temp = s.substr(0,10);
		if(temp=="Simon says"){
			for(int i=10;i<len;i++){
				cout<<s[i];
			}
		}else continue;
	}
	return 0;
}
