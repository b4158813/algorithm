#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,a[100005];
int vis[100005],biao[100005],cnt;
set<int> se;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],se.insert(a[i]);
    for(int i=n;i>=1;i--){
    	if(se.find(a[i])!=se.end()&&!vis[a[i]]) cnt++,biao[i]=1,vis[a[i]]=1;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++){
		if(biao[i]==1) cout<<a[i]<<" ";
	}
    return 0;
}

