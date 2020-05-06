#include<bits/stdc++.h>
using namespace std;

map <string,string> ans;
map <string,char> sb;
int main(){
	int n,q;
	cin>>n>>q;
	while(n--){
		string tm,da;
		cin>>tm>>da;
		ans[tm] = da;
	}
	while(q--){
		string ti,s1,s2,s3,s4;
		cin>>ti>>s1>>s2>>s3>>s4;
		sb[s1]='A';sb[s2]='B';sb[s3]='C';sb[s4]='D';
		cout<<sb[ans[ti]]<<endl;
	}
	return 0;
}
