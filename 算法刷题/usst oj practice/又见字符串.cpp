#include<bits/stdc++.h>
using namespace std;

string s;
string t="";
int l,r;

int main(){
	cin>>s;
	l=0,r=s.length()-1;
	int len = s.length();
	while(len--){
		if(s[l]>s[r]){
			t.push_back(s[l]);
			l++;
		}else{
			t.push_back(s[r]);
			r--;
		}
	}
	cout<<t<<endl;
	return 0;
}
