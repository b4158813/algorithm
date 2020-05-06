#include<bits/stdc++.h>
using namespace std;

template <typename T>

int compare(const T &a, const T &b){
	if(a<b) return -1;
	if(b<a) return 1;
	return 0;
}

int main(){
	string a="fbc",b="def";
	int c=3,d=5;
	cout<<compare(a,b)<<endl;
	cout<<compare(c,d)<<endl;
	return 0;
} 
