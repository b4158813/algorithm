#include<bits/stdc++.h>
using namespace std;

struct node {
	int x,y;
}st[1005];
int n,t;
bool cmp(node x1,node x2){
	return x1.x<x2.x;
}
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>st[i].x>>st[i].y;
	}
	sort(st+1,st+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		while(st[i].x<=t&&st[i].y>0){
			t-=st[i].x;
			st[i].y--;
			ans++;
		}
		if(t==0) break;
	}
	if(t==0) cout<<ans<<endl;
	else cout<<0<<endl;
	return 0;
}
