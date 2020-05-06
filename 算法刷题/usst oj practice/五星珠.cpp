#include<bits/stdc++.h>
using namespace std;

int n;
int h[50005];

int dfs(int l, int r){
	if(l>r) return 0;
	int fst = l;
	int minx = 1<<30,ans=0;
	for(int i=l;i<=r;i++){
		minx = min(minx,h[i]);
	}
	for(int i=l;i<=r;i++){
		h[i]-=minx;
	}
	ans+=minx;
	for(int i=l;i<=r;i++){
		if(h[i]==0){
			ans+=dfs(fst,i-1);
			fst=i+1;
		}else if(i==r){
			ans+=dfs(fst,r);
		}
	}
	return min(ans,r-l+1);
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	} 
	cout<<dfs(1,n)<<endl;
	return 0;
}
