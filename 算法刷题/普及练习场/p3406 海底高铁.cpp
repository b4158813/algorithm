#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p[100005],a[100005],b[100005],c[100005];
ll cc[100005],sum[100005];
ll ans;

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n-1;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<m;i++){
		int minx = min(p[i],p[i+1]);
		int maxx = max(p[i],p[i+1]);
		sum[minx]++;
		sum[maxx]--;
	}
	for(int i=1;i<=n-1;i++){
		sum[i] = sum[i]+sum[i-1];
	}
	for(int i=1;i<n;i++){
		ans+=min(a[i]*sum[i],b[i]*sum[i]+c[i]);
	}
	cout<<ans<<endl;
	return 0;
}
