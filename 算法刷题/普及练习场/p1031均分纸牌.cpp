#include<bits/stdc++.h>
using namespace std;

int a[105];

int main(){
	int n,mean,sum=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	mean=sum/n;
	for(int i=0;i<n;i++){
		if(a[i]-mean){
			a[i+1]=a[i+1]+a[i]-mean;cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
