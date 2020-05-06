#include<bits/stdc++.h>
using namespace std;
int a[100005],p[100005];
void msort(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	msort(l,mid);msort(mid+1,r);
	int i=l,j=mid+1,t=l;
	while(i<=mid&&j<=r){
		if(a[i]>a[j]){
			p[t++]=a[j++];
		}
		else p[t++]=a[i++];
	}
	while(i<=mid) p[t++]=a[i++];
	while(j<=r) p[t++]=a[j++];
	for(int k=l;k<=r;k++){
		a[k]=p[k];
	}
	return;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	msort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
