#include<bits/stdc++.h>
using namespace std;
const double gold = 0.6180339887498949;
const double eps = 1e-6;
const double inf = 1<<30;
int n;
double a[30005];
double cha=inf,temp;
int ans1,ans2;

bool check(int x,int y){
	temp = a[x]/a[y]-gold;
	if(temp<-eps) return 0;
	return 1;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		int l=1,r=i;
		while(l<r){
			int mid = (l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
	//	cout<<l<<" "<<i<<endl;
		if(fabs(a[l]/a[i]-gold)<fabs(a[l-1]/a[i]-gold)){
			temp = a[l]/a[i]-gold;
		}else{
			temp=a[l-1]/a[i]-gold;
			l=l-1;
		}
	//	cout<<temp<<endl;
		if(fabs(temp)<=fabs(cha)){
			cha = temp;
			ans1 = a[l];
			ans2 = a[i];
		}
	}
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}
