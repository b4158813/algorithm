#include<bits/stdc++.h>
using namespace std;

set<string> se;
int main(){
	int n;
	cin>>n;
	int ans=0;
	while(n--){
		string s;
		cin>>s;
		if(se.find(s)==se.end()){
			se.insert(s);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
