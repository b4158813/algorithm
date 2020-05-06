#include<bits/stdc++.h>
using namespace std;
int n;
struct Edge{
	int v,next;
}e[500005];
int cnt,head[500005],used1[40005],used2[40005],have1[40005],have2[40005];
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
bool Hungary(int u){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!used1[v]){
			used1[v]=1;
			if(!have1[v]||Hungary(have1[v])){
				have1[v]=u;
				return true;
			}
		}else if(!used2[v]){
			used2[v]=1;
			if(!have2[v]||Hungary(have2[v])){
				have2[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	int s1,s2;
	for(int i=1;i<=2*n;i++){
		scanf("%d%d",&s1,&s2);
		addedge(i,s1);
		addedge(i,s2);
	}
	int ans=0;
	for(int i=1;i<=2*n;i++){
		memset(used1,0,sizeof(used1));
		memset(used2,0,sizeof(used2));
		if(Hungary(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
