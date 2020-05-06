#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
double a[maxn];
int b[maxn];
int main(){
	int x;
	cin>>x;
	for(int i=1;i<=x;i++){
		int e;
		double c;
		cin>>e>>c;
		a[e]+=c;
	}
	cin>>x;
	for(int i=1;i<=x;i++){
		int e;
		double c;
		cin>>e>>c;
		a[e]+=c;
	}
	int cnt=0;
	for(int i=0;i<=maxn;i++){
		if(a[i]!=0) cnt++;
	}
	cout<<cnt;
	for(int i=maxn;i>=0;i--){
		if(a[i]!=0){
			printf(" %d %.1lf",i,a[i]);
		}
	}
	return 0;
} 
