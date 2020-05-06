#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
long double a[maxn];
long double b1[maxn],b2[maxn];
//priority_queue<long double,vector<long double>,greater<long double> > pq;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int n;
	//while(1){
		cin>>n;
		long double sum=0.0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			sum+=a[i];
			b1[i]=sum/(i+1)*sum;
		}
		sort(a,a+n,cmp);
		sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
			b2[i]=sum/(i+1)*sum;
		}
		sort(b1,b1+n);
		sort(b2,b2+n);
		//for(int i=0;i<n;i++) cout<<b[i]<<endl;
		printf("%.16Lf\n",max(b1[n-1],b2[n-1]));
	//}
	return 0;
}
