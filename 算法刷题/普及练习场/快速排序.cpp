#include<bits/stdc++.h>
using namespace std;

int a[100000005];

void qsort(int l, int r){
	int i=l,j=r,key=a[(l+r)>>1];
	do{
		while(a[i]<key) i++;
		while(a[j]>key) j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;j--;
		}
	} while(i<=j);
	if(l<j) qsort(l,j);
	if(r>i) qsort(i,r);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	qsort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
