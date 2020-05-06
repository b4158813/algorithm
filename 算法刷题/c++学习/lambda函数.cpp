#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string> a;
	a.push_back("abc");
	a.push_back("dcs");
	a.push_back("dt");
	a.push_back("qweqf");
	sort(a.begin(),a.end(),[](const string &a,const string &b){
		return a.length()<b.length();
	});
	
	for(auto i=a.begin();i!=a.end();i++) cout<<*i<<" ";
	return 0;
}
