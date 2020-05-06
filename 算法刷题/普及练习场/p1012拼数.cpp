#include<bits/stdc++.h>
using namespace std;

string a[25];

bool cmp(string x,string y){
	//lx=x.length();
	//ly=y.length();
	int i=0;
	while(1){
		if(x[i%x.length()]>y[i%y.length()]) return 1;
		else if(x[i%x.length()]==y[i%y.length()]) i++;
		else return 0;
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
