#include<bits/stdc++.h>
using namespace std;

int a[30005];

int main(){
	int w,n;
	cin>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int i=1,j=n;
	int cnt=0,sum;
	while(i<=j){
		if(i!=j){
			if(a[i]+a[j]<=w){
				cnt++;j--;i++;
			}
			else if(a[i]>a[j]){
				cnt++;i++;
			}
			else if(a[i]<a[j]){
				cnt++;j--;
			}
		}
		else{
			if(a[i]<=w) cnt++;
			i++;
		}
	}
	cout<<cnt<<endl;;
	return 0;
}
