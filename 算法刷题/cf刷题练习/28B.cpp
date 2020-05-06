#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,a[1005],b[1005];
int fa[10005];
inline void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void unite(int x,int y){
	fa[find(x)]=find(y);
}

int main() {
    scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		int d1=i+b[i],d2=i-b[i];
		if(d1<=n&&d1>=1) unite(d1,i);
		if(d2<=n&&d2>=1) unite(d2,i);
	}
	for(int i=1;i<=n;i++){
		if(find(a[i])!=find(i)){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
    return 0;
}

