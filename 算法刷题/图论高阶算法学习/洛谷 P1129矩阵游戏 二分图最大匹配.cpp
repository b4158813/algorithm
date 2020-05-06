#include<bits/stdc++.h>
using namespace std;
int t,n,a[205][205];
int used[205],have[205];
bool Hungary(int x){
	for(int i=1;i<=n;i++){
		if(!used[i]&&a[x][i]){
			used[i]=1;
			if(!have[i]||Hungary(have[i])){
				have[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(have,0,sizeof(have));
		scanf("%d",&n);
		int x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&x);
				if(x==1) a[i][j]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(used,0,sizeof(used));
			if(Hungary(i)) ans++;
		}
		if(ans==n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
