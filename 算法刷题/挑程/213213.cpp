#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x,y;
}a[50005];
bool cmp(node x1,node x2){
	if(x1.x==x2.x) return x1.y<x2.y;
	return x1.x<x2.x; 
}
int sum;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	int pos=a[1].x,maxy=a[1].y;
	for(int i=1;i<=n;i++){
		if(maxy>=a[i+1].x) maxy=max(maxy,a[i+1].y);
		else{
			sum+=maxy-pos;
			pos=a[i+1].x;
			maxy=a[i+1].y;
		}
		if(i==n){
			sum+=maxy-pos;
		}
	}
	cout<<sum<<endl;
	return 0;
}
