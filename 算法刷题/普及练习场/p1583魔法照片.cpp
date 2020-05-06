#include<bits/stdc++.h>
using namespace std;

struct p{
	int i,e,w,c;
}man[20005];

bool cmpw(p m1,p m2){
	if(m1.w==m2.w){
		return m1.i<m2.i;
	}
	return m1.w>m2.w;
}

int m[20005];

int main(){
	int n,k;
	cin>>n>>k;
	for(int j=1;j<=10;j++){
		cin>>m[j];
	}
	for(int j=1;j<=n;j++){
		cin>>man[j].w;
		man[j].i=j;
	}
	sort(man+1,man+n+1,cmpw);
	for(int i=1;i<=n;i++){
		man[i].c=(i-1)%10+1;
	}
	for(int i=1;i<=n;i++){
		man[i].w+=m[man[i].c];
	}
	sort(man+1,man+n+1,cmpw);
	for(int i=1;i<=k;i++){
		cout<<man[i].i<<" ";
	}
	return 0; 
}
