#include<bits/stdc++.h>
using namespace std;
double a[10005];
double ans;
int n,k; 
bool check(double x){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i]/x;
	}
	if(sum>=k) return false;
	else return true;
}
int main(){
	cin>>n>>k;
	double maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]*=1000;
		maxx=max(maxx,a[i]);
	}
	double l=0,r=maxx;
	while(l<=r){
		double mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%.2lf\n",floor(l/10)/100);
	return 0;
}
