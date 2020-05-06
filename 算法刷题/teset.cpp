#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
int main() {
    while(cin>>s1){
    	cin>>s2;
    	s1+=s1;
    	if(s1.find(s2)!=s1.npos) cout<<"yes"<<endl;
    	else cout<<"no"<<endl;
	}
    return 0;
}

