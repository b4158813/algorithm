#include<bits/stdc++.h>
using namespace std;
const double inf = 1<<30;
int n,m;
double a[10005];
//int d[10005];

bool check(double x){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=floor(a[i]/x);
	}
	return sum>=m;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	double l=0,r=inf;
	while(r-l>1e-4){
		double mid = (l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	char ans[25];
	sprintf(ans,"%.2lf",l);
	ans[strlen(ans)-1]='\0';
	cout<<ans<<endl;
	return 0;
}
