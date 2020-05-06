#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n,m,a[55][55],ans;
char cc[55][55];
inline int gao(int x1,int y1,int x2,int y2){
	int cnt=0;
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			if(a[i][j]==1){
				return 0;
			}
		}
	}
	return 2*((x2-x1+1)+(y2-y1+1));
}
inline void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				for(int h=j;h<=m;h++){
					ans=max(ans,gao(i,j,k,h));
				}
			}
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>cc[i][j];
			a[i][j]=cc[i][j]-'0';
		}
	}
	solve();
	printf("%d\n",ans);
    return 0;
}

