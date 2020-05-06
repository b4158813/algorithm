#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,a[105],b[105];
ll minx,maxx;

bool cmp(ll x,ll y){
	return x>y;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		a[i]=a[i]*a[i-1]+1;
	}
	maxx = a[n];
	sort(b+1,b+n+1,cmp);
	for(int i=2;i<=n;i++){
		b[i]=b[i]*b[i-1]+1;
	}
	minx = b[n];
	cout<<maxx<<" "<<minx<<endl;
	return 0;
}
