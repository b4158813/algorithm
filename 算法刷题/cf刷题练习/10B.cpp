#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,k,vis[105][105];

int main() {
    scanf("%d%d",&n,&k);
    int xc=(k+1)>>1,yc=(k+1)>>1;
	while(n--){
		int x;
		scanf("%d",&x);
		int minh=1e9;
		int ansh,ansl,ansr;
		for(int h=1;h<=k;h++){
			for(int i=1;i<=k-x+1;i++){
				bool f=true;
				int dis=0;
				for(int j=i;j<=i+x-1;j++){
					if(vis[h][j]){
						f=false;
						break;
					}
					dis+=abs(h-xc)+abs(j-yc);
				}
				if(f&&dis<minh){
					minh=dis;
					ansh=h,ansl=i,ansr=i+x-1;
				}
			}
		}
		if(minh==1e9) printf("-1\n");
		else{
			for(int i=ansl;i<=ansr;i++) vis[ansh][i]=1;
			printf("%d %d %d\n",ansh,ansl,ansr);
		}
	}
    return 0;
}

