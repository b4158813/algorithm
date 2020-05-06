#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
bool mm[125][125];


inline void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mm[i][k]&&mm[k][j]){
					mm[i][j]=1;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	memset(mm,false,sizeof(mm));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		mm[x][y]=true;
	}
	floyd();
	int ans=0;
	for(int i=1;i<=n;i++){
		bool f=true;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(!mm[i][j]&&!mm[j][i]){
				f=false;
				break;
			}
		}
		if(f) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
