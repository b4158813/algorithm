#include<bits/stdc++.h>
using namespace std;

struct p{
	int x;
	string s;
}a[25];

bool cmp(p z, p y){
	//string s1=z.s;
//	string s2=y.s;
	if(z.s.length()>y.s.length()) return true;
	else if(z.s.length()==y.s.length()) {
		for(int i=0;i<z.s.length();i++){
			if(z.s[i]>y.s[i]) return true;
			else if(z.s[i]==y.s[i]) continue;
			else if(z.s[i]<y.s[i]) return false;
		}
	} else return false;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].s;
		a[i].x=i+1;
	}
	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++){
//		cout<<a[i].x<<" "<<a[i].s<<endl;
//	}
	cout<<a[0].x<<endl<<a[0].s<<endl;
	return 0;
	
}
