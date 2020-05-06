#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn=10000;
const int mod=1e9+7;
int n;
double a[20];
double l,r;

//inline double dfunc(double x){
//	double ans=0;
//	for(int i=n;i>=1;i--){
//		ans+=a[i]*i*pow(x,i-1);
//	}
//	return ans;
//}

inline double func(double x){
	double ans=0;
	for(int i=n;i>=0;i--){
		ans=ans*x+a[i];
	}
	return ans;
}

int main() {
    scanf("%d%lf%lf",&n,&l,&r);
    for(int i=n;i>=0;i--){
    	scanf("%lf",&a[i]);
	}
	while(r-l>1e-8){
		double k=(r-l)/3.0;
		double mid1=l+k,mid2=r-k;
//		printf("%lf\n",mid);
		if(func(mid1)<func(mid2)) l=mid1;
		else r=mid2;
	}
	printf("%.5lf\n",l);
    return 0;
}

