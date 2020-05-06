#include <bits/stdc++.h>
using namespace std;

int f[3000]={6,2,5,5,4,5,6,3,7,6};
int ans=0;
int main(){
	
	int i;
	for(i=10;i<=2000;i++){
		f[i]=f[i/10]+f[i%10];
	}
	int n;
	cin>>n;
	n=n-4;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			if(f[i]+f[j]+f[i+j]==n) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
