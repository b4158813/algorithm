#include<bits/stdc++.h>
using namespace std;
#define ls (i<<1)
#define rs (i<<1|1)
const int N=2e5+5;
int n,m,b[N],c[N],cnt=1;
struct node{
	int val,id;
}a[N];
bool cmp(node x1,node x2){
	return x1.val<x2.val;
}
struct Stree{
	int l,r,v;
}tr[N<<2];
inline void build(int i,int l,int r){
	tr[i].l=l,tr[i].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
inline void update(int i,int x){
	if(tr[i].l==tr[i].r){
		tr[i].v++;
		return;
	}
	if(tr[ls].r>=x) update(ls,x);
	else update(rs,x);
	tr[i].v=tr[ls].v+tr[rs].v;
}
inline int getval(int i,int k){
	if(tr[i].l==tr[i].r){
		return tr[i].l;
	}
	if(tr[ls].v>=k) return getval(ls,k);
	else return getval(rs,k-tr[ls].v);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].val),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) c[a[i].id]=i;
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    build(1,1,n);
    for(int i=1;i<=n;i++){
    	update(1,c[i]);
    	while(b[cnt]==i){
    		printf("%d\n",a[getval(1,cnt)].val); 
    		cnt++;
		}
	}
    return 0;
}

