#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll ans;
string a="abcdefghijklmnopqrstuvwxyz";
int biao[26];
inline ll gcd(ll x,ll y){
	if(x%y==0) return y;
	else return gcd(y,x%y);
}

int main(){
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		biao[int(s[i]-'a')]=1;
	}
	
	if(len==26){
		for(int i=24;i>=0;i--){
			biao[s[i+1]-'a']=0;
			for(int j=0;j<26;j++){
				if(!biao[j]&&j>s[i]-'a'){
					for(int k=0;k<i;k++) cout<<s[k];
					cout<<a[j];
					return 0;
				}
			}
		}
		cout<<"-1";
		return 0;
	}
	
	cout<<s;
	for(int i=0;i<26;i++){
		if(biao[i]==0){
			cout<<a[i]<<endl;
			return 0;
		}
	}
	return 0;
}
