#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5e7;

int n,_,f[100005],sg[100005],vis[100005];
inline void get_sg(int n){
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=1;f[j]<=i&&j<=n;j++){
			vis[sg[i-f[j]]]=1;
		}
		for(int j=0;j<=n;j++){
			if(vis[j]==0){
				sg[i]=j;
				break;
			}
		}
	}
}
int main(){
	for(int i=1;i<=10001;i++) f[i]=i;
	get_sg(10001);
	// freopen("P2197_1.in","r",stdin);
	for(scanf("%d",&_);_;_--){
		scanf("%d",&n);
		int ans=0,x;
		for(int i=1;i<=n;i++)
			scanf("%d",&x),ans^=sg[x];
		ans==0?puts("No"):puts("Yes");
	}
	return 0;
}