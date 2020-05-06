#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],f[100005];
int fun[100005],len;

int bound(int x){
	int l=1,r=len;
	while(l<r){
		int mid = (l+r)>>1;
		if(f[mid]>x){
			r = mid;
		}else l = mid +1;
	}
	return l;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fun[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(f[len]<fun[b[i]]){
			f[++len] = fun[b[i]];
		}else{
			int pos = bound(fun[b[i]]);
			f[pos] = fun[b[i]];
		}
	}
	cout<<len<<endl;
	return 0;
}
