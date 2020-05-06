#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
bool vis[1000];
string gs(ll x){
	string s="";
	while(x){
		char c='0'+x%2;
		s=s+c;
		x/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
int main() {
	vector<ll> vec;
    for(ll i=1;i<=200;i++){
    	for(ll j=i+1;j<=200;j++){
    		for(ll k=j+1;k<=200;k++){
    			if((i^j^k)==0&&!vis[i]&&!vis[j]&&!vis[k]){
    				vis[i]=vis[j]=vis[k]=1;
    				vec.push_back(i);
    				vec.push_back(j);
    				vec.push_back(k);
				}
			}
		}
	}
	
	for(int i=0;i<vec.size();i+=3){
		printf("%d %d %d\n",vec[i],vec[i+1],vec[i+2]);
	}
    return 0;
}

