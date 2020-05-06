#include<bits/stdc++.h>
using namespace std;
int a[300005];
int dp1[300005],dp2[300005];
int len1,len2;
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<k;i++){
		if(dp1[len1]<a[i]&&a[i]<a[k]) dp1[++len1] = a[i];
		else if(a[i]<a[k]){
			int pos = lower_bound(dp1+1,dp1+1+len1,a[i])-dp1;
			dp1[pos] = a[i];
		}
	}
	for(int i=k+1;i<=n;i++){
		if(dp2[len2]<a[i]&&a[i]>a[k]) dp2[++len2] = a[i];
		else if(a[i]>a[k]){
			int pos = lower_bound(dp2+1,dp2+1+len2,a[i])-dp2;
			dp2[pos] = a[i];
		}
	}
	cout<<len1+len2+1<<endl;
	return 0;
}
