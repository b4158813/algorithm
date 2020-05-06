#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=m;i++){
			if(i!=m) printf("%d ",a[i]);
			else printf("%d\n",a[i]);
		}
	}
	return 0;
}
