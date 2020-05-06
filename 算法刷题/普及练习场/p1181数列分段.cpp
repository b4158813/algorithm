#include<bits/stdc++.h>
using namespace std;

long long a[100005];

int main(){
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int i=0,cnt=0;
	long long sum=0;
	while(i<n){
		sum=0;
		while(1){
			sum+=a[i];
			if(i<n&&sum>m) {
				cnt++;
				break;
			}
			else if(i==n-1){
				i++;cnt++;break;
			}
			i++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
