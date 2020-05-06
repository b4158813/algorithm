#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int inf=1e8;
int n,m,mm[105][105];

inline void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mm[i][j]=min(mm[i][j],mm[i][k]+mm[k][j]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(j!=i) mm[i][j]=inf;
			
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		mm[x][y]=1;
	}
	floyd();
	int ans=0;
	for(int i=1;i<=n;i++){
		bool f=true;
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(mm[i][j]==inf&&mm[j][i]==inf){
					f=false;
					break;
				}
			}
		}
		if(f) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
