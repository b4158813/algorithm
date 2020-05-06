#include<iostream> 
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,e,ans,mm[1015][1015],have[1015],used[1015];
bool Hungary(int x){
	for(int i=1;i<=m;i++){
		if(!used[i]&&mm[x][i]){
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
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=e;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>n||v>m) continue;
		mm[u][v]=1;
	}
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		if(Hungary(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
