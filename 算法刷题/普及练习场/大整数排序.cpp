#include<bits/stdc++.h>
using namespace std;

string a[105];

bool cmp(string p1,string p2){
	if(p1.length()==p2.length()){
		return p1<p2; 
	}
	return p1.length()<p2.length();
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
} 
