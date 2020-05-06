#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ST[100005][23];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
inline void init(){
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))-1<=n;i++){
			ST[i][j]=max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int query(int l,int r){
	int len=log2(r-l+1);
	return max(ST[l][len],ST[r-(1<<len)+1][len]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) 
		a[i]=read(),ST[i][0]=a[i];
	init();
	int l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
