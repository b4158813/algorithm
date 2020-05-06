#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() { 
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}
struct Edge{
	int u,v,next;
}e[6000005];
int n,cnt,head[6000006];
inline void addedge(int u,int v){
	e[cnt]=Edge{u,v,head[u]};
	head[u]=cnt++;
}
int id,used[6000006],have[6000006];
bool Hungary(int u){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(used[v]!=id){
			used[v]=id;
			if(!have[v]||Hungary(have[v])){
				have[v]=u,have[u]=v;
				return true;
			}
		}
	}
	return false;
}
int main(){
	n=read();
	memset(head,-1,sizeof(head));
	int x,y;
	for(int i=1;i<=n;i++){
		x=read(),y=read();
		addedge(x,n+i);
		addedge(n+i,x);
		addedge(y,n+i);
		addedge(n+i,y);
	}
	int ans=0;
	for(int i=1;i<=10000;i++){
		id++;
		if(Hungary(i)) ans++;
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
