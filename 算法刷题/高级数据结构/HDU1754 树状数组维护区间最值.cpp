#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,m,a[200005],c[200005];
inline int lowbit(int x){return x&-x;}
inline void update(int x,int y){
	a[x]=y; 
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i]=y;
		for(int j=1;j<lowbit(i);j<<=1){
			c[i]=max(c[i],c[i-j]);
		}
	}
}
inline int getmax(int x,int y){
	int ans=0;
	while(x<=y){
		ans=max(ans,a[y]);
		for(--y;y-lowbit(y)>=x;y-=lowbit(y)){
			ans=max(ans,c[y]);
		}
	}
	return ans;
}

int main() {
    while(~scanf("%d%d",&n,&m)){
    	for(int i=1;i<=n;i++){
    		scanf("%d",&a[i]);
    		update(i,a[i]);
		}
		char c[2];
		int x,y;
		for(int i=1;i<=m;i++){
			scanf("%s%d%d",c,&x,&y);
			if(c[0]=='U') update(x,y);
			else printf("%d\n",getmax(x,y));
		}
	}
    return 0;
}

