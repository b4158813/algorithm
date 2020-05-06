#include<bits/stdc++.h>
using namespace std;
int vis[30];
int main(){
	int n;
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		string s;
		getline(cin,s);
		int len=s.length();
		for(int i=0;i<len;i++){
			if(isalpha(s[i])) {
				s[i]=tolower(s[i]);
				vis[s[i]-'a']++;
			}
		}
	//	for(int i=0;i<26;i++) cout<<vis[i]<<endl;
		bool f=false;
		for(int i=0;i<26;i++){
			if(vis[i]==0){
				f=true;
				cout<<"missing"<<" ";
				break;
			}
		}
		if(f){
			for(int i=0;i<26;i++){
				if(vis[i]==0) cout<<char('a'+i);
			}
		}else cout<<"pangram";
		cout<<endl;
	}
}
