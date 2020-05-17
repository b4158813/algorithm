#include<iostream>
#include<stack>
using namespace std;
string s;
string a[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
inline void Count(string t){
	int ans=0;
	for(int i=0;i<(int)t.size();i++){
		ans+=(t[i]-'0');
	}
	stack<string> sta;
	while(ans){
		sta.push(a[ans%10]);
		ans/=10;
	}
	while(sta.size()>1){
		cout<<sta.top()<<" ";
		sta.pop();
	}
	if(sta.size()) cout<<sta.top();
	else cout<<"zero";
}

int main(){
	cin>>s;
	Count(s);
	return 0;
}