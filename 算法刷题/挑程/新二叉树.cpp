#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	for(int i=2;i<=n;i++){
		string ss;
		cin>>ss;
		int pos=s.find(ss[0]);
		s.erase(pos,1);
		s.insert(pos,ss);
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='*') cout<<s[i];
	}
	return 0;
}
