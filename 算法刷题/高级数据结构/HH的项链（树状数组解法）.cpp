#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],c[N],ans[N];
int vis[N];
struct node{
	int l,r,pos;
}b[N];
bool cmp(node x1,node x2){
	return x1.r<x2.r;
}
inline int lowbit(int x){
	return x&-x;
}
inline void add(int i,int x){
	while(i<=n) c[i]+=x,i+=lowbit(i);
}
inline int getsum(int i){
	int ans=0;
	while(i) ans+=c[i],i-=lowbit(i);
	return ans;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
    	scanf("%d%d",&b[i].l,&b[i].r);
    	b[i].pos=i;
	}
	sort(b+1,b+1+m,cmp);
	int next=1;
	for(int i=1;i<=m;i++){
		for(int j=next;j<=b[i].r;j++){
			if(vis[a[j]]){
				add(vis[a[j]],-1);
			}
			add(j,1);
			vis[a[j]]=j;
		}
		next=b[i].r+1;
		ans[b[i].pos]=getsum(b[i].r)-getsum(b[i].l-1);
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
    return 0;
}

