#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,a[100005],c[100005];
inline int lowbit(int x){return x&-x;}
inline void update(int i,int k){
	while(i<=n) c[i]+=k,i+=lowbit(i);
}
inline int getsum(int i){
	int res=0;
	while(i) res+=c[i],i-=lowbit(i);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
    int T;cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			update(i,a[i]);
		}
		string s;
		cout<<"Case "<<o<<":"<<endl;
		while(cin>>s){
			if(s=="End")break;
			int a,b;
			cin>>a>>b;
			if(s=="Add") update(a,b);
			if(s=="Sub") update(a,-b);
			if(s=="Query") cout<<getsum(b)-getsum(a-1)<<endl;
		}
	}
    return 0;
}

