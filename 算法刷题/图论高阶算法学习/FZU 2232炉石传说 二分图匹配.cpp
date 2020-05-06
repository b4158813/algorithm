#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int n,a[105],b[105],c[105],d[105];
int ans,mm[205][205],id,used[205],have[205];
bool Hungary(int x){
	for(int i=1;i<=n;i++){
		if(mm[x][i]&&used[i]!=id){
			used[i]=id;
			if(!have[i]||Hungary(have[i])){
				have[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main() {
    int T;
	scanf("%d",&T);
	for(int o=1;o<=T;o++){
		memset(mm,0,sizeof(mm));
		memset(have,0,sizeof(have));
		memset(used,0,sizeof(used));
		id=ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]>d[j]&&b[i]>=c[j]){
					mm[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			id++;
			if(Hungary(i)) ans++;
		}
		if(ans==n) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}

