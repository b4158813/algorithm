#include<bits/stdc++.h>
using namespace std;
int n,fun[200005];
int f[200005],len;
struct node{
	int a,b;
}p[200005];

bool cmp(node x1,node x2){
	return x1.a<x2.a;
}
int bound(int x){
	int l=1,r=len;
	while(l<r){
		int mid = (l+r)>>1;
		if(f[mid]>x) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(p[i].b>f[len]){
			f[++len] = p[i].b;
		}else{
			int pos = bound(p[i].b);
			f[pos] = p[i].b;
		}
	}
	cout<<len<<endl;
	return 0;
}
