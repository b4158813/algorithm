#include<bits/stdc++.h>
using namespace std;

int a[1000005]; 
int f[1000005];
int l,r;

int main(){
	cin>>l>>r;
	a[1]=1;
	for(int i=1;i<=r;i++){
		if(a[i]==0){
			for(int j=i*2;j<=r;j+=i){
				a[j]=1;
			}
		}
	}
	a[4]=0;
	for(int i=1;i<=r;i++){
		if(a[i]==0) f[i]=f[i-1]+1;
		else f[i]=f[i-1];
	//	cout<<f[i]<<" ";
	}
	cout<<f[r]-f[l-1]<<endl; 
	return 0;
}
