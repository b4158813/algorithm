#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,a[10005];
string s[10005];
int main() {
    scanf("%d",&n);
    int x;
    map<string,int> ma,mb;
    map<string,int>::iterator it;
    int ansn=0;
    string ans;
    for(int i=1;i<=n;i++){
    	cin>>s[i]>>a[i];
    	ma[s[i]]+=a[i];
	}
	for(it=ma.begin();it!=ma.end();it++){
		if(it->second>ansn){
			ansn=it->second;
			ans=it->first;
		}
	}
	for(int i=1;i<=n;i++){
		mb[s[i]]+=a[i];
		if(mb[s[i]]>=ansn&&ma[s[i]]>=ansn){
			cout<<s[i]<<endl;
			return 0;
		}
	}
    return 0;
}

