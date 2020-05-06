#include<bits/stdc++.h>
using namespace std;

map<char,char> m;
bool f=true;

int main(){
	string a,b,d;
	cin>>a>>b>>d;
	for(int i=0;i<a.length();i++){
		if(m.count(a[i])&&m[a[i]]!=b[i]){
			f=false;
			break;
		}
		m[a[i]]=b[i];
		if(i==a.length()-1){
			for(int j=0;j<26;j++){
				if(!m.count('A'+j)){
					f=false;
					break;
				}
			}
		}
		int cnt=0;
		if(i==a.length()-1){
			for(int j=0;j<26;j++){
				if(m['A'+j]=='A'+j) cnt++;
			}
			if(cnt==25){
				f=false;break;
			}
		}
	}
	if(!f) cout<<"Failed"<<endl;
	else {
		for(int i=0;i<d.length();i++){
			cout<<m[d[i]];
		}
	}
	return 0;
}
