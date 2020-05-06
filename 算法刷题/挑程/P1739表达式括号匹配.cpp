#include<bits/stdc++.h>
using namespace std;
int ans;
char s[1005];
int main(){
	cin>>s;
	int len=strlen(s);
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]=='(') {
			ans++;
		}
		else if(s[i]==')') {
			if(ans==0&&cnt==0) cnt++;
			ans--;
		}
	}
	if(ans==0&&cnt==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
