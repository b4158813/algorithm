#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[20];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=a[1];
	for(int i=2;i<=n;i++) ans=__gcd(ans,a[i]);
	cout<<abs(ans)<<endl;
	return 0;
}
