#include<bits/stdc++.h>
using namespace std;
int n;
char a[2500][2500];

int kpow(int x,int y){
	int ans=1,base=x;
	while(y>0){
		if(y&1) ans*=base;
		base*=base;
		y>>=1;
	}
	return ans;
}

void getright(int x){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=2*x;j++){
			a[i][j+2*x] = a[i][j];
		}
	}
}

void getdown(int x){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=2*x;j++){
			a[i+x][j+x] =a[i][j];
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=2500;i++){
		for(int j=1;j<=2500;j++){
			a[i][j]=' ';
		}
	}
	a[1][1]='\\';
	a[1][2]='_',a[1][3]='_';
	a[1][4]='/';
	a[2][2]='\\',a[2][3]='/';
	for(int i=1;i<=n;i++){
		int h=kpow(2,i);
		getright(h);
		getdown(h);
	}
	for(int i=kpow(2,n);i>=1;i--){
		for(int j=kpow(2,n+1);j>=1;j--){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
