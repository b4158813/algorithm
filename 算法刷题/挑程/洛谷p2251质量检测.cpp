#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n,m,a[N],ST[N][23];

inline void init(){
	int len=log2(N);
	for(int j=1;j<=len;j++){
		for(int i=1;i+(1<<(j-1))-1<=n;i++){
			ST[i][j]=min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int query(int l,int r){
	int len=log2(r-l+1);
	return min(ST[l][len],ST[r-(1<<len)+1][len]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]),ST[i][0]=a[i];
	init();
	for(int i=1;i<=n-m+1;i++){
		printf("%d\n",query(i,i+m-1));
	} 
	return 0;
}
