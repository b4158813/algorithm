#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	int t;cin>>t;
	getchar();
	while(t--){
		getline(cin,s);
		int cnt=0;
		for(int i=0;i<s.length();i++){
			if(s[i]<0) cnt++;
		}
		cout<<cnt/2<<endl;
	}
	return 0;
}
