#include<bits/stdc++.h>
using namespace std;

map <string, int> m;
int a[10005];
bool cmp(int x,int y){
	if(x<10||y<10) return x<y;
	return x/10<y/10;
}

int main(){
	m["one"]=1;
	m["two"]=2;
	m["three"]=3;
	m["four"]=4;
	m["five"]=5;
	m["six"]=6;
	m["seven"]=7;
	m["eight"]=8;
	m["nine"]=9;
	m["ten"]=10;
	m["eleven"]=11;
	m["twelve"]=12;
	m["thirteen"]=13;
	m["fourteen"]=14;
	m["fifteen"]=15;
	m["sixteen"]=16;
	m["seventeen"]=17;
	m["eighteen"]=18;
	m["nineteen"]=19;
	m["twenty"]=20;
	string s[10];
	for(int i=0;i<6;i++){
		cin>>s[i];
	}
//	for(int i=0;i<6;i++){
//		cout<<s[i]<<" ";
//	}
	int k=0;
	for(int i=0;i<6;i++){
		if(m.count(s[i])) a[k++]=m[s[i]]*m[s[i]];
		if(s[i]=="a"||s[i]=="first") a[k++]=1;
		if(s[i]=="both"||s[i]=="another"||s[i]=="second") a[k++]=4;
		if(s[i]=="third") a[k++]=9;
	} 
	sort(a,a+k,cmp);
	//for(int i=0;i<k;i++) cout<<a[i]<<" ";
	for(int i=0;i<k;i++){
		if(a[i]<10&&i!=0) cout<<0;
		cout<<a[i];
	}
	if(k==0) cout<<0;
	return 0;
}
