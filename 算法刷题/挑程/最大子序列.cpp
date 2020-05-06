#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
int st[1000005][22],a[1000005],n,m,ans[1000005],cnt;
inline void init(){
	for(int i=1;i<=n;i++) st[i][0]=i;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))-1<=n;i++){
			int ta=st[i][j-1],tb=st[i+(1<<(j-1))][j-1];
			if(a[ta]>=a[tb]) st[i][j]=ta;
			else st[i][j]=tb;
		}
	}
}
inline int query(int l,int r){
	int len=log2(r-l+1);
	int ta=st[l][len],tb=st[r-(1<<len)+1][len];
	if(a[ta]>=a[tb]) return ta;
	else return tb;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		cnt=0;
		memset(st,0,sizeof(st));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		init();
		int l=1,r=n-m+1;
		while(m--){
			int c=query(l,r);
			ans[++cnt]=c;
			l=c+1;
			r++;
		}
		for(int i=1;i<=cnt;i++){
			printf("%d ",a[ans[i]]);
		}
		puts("");
	}
	return 0;
}
