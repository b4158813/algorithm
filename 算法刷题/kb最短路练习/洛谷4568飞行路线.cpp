#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1ll<<60;
inline ll read() {
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}
int cnt,head[8000005];
ll dis[8000005];
int n,m,k,st,en;
struct Edge{
	int u,v,w,next;
}e[8000005]; 
struct node{
	int u,dis;
	bool operator<(const node&rhs)const {
		return dis>rhs.dis;
	}
};

inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline void dij(int st){
	memset(dis,0x3f3f,sizeof(dis));
	dis[st]=0;
	priority_queue<node> q;
	q.push(node{st,0});
	while(!q.empty()){
		node q1=q.top();q.pop();
		ll u=q1.u,d=q1.dis;
		if(d>dis[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			ll v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(node{v,dis[v]});
			}
		}
	}
}

int main(){
	n=read(),m=read(),k=read();
	st=read(),en=read();
	int u,v,w;
	for(int i=0;i<m;i++){
		u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
		for(int j=1;j<=k;j++){
			addedge(u+(j-1)*n,v+j*n);
			addedge(v+(j-1)*n,u+j*n);
			addedge(u+j*n,v+j*n,w);
			addedge(v+j*n,u+j*n,w);
		}
	}
	for(int i=1;i<=k;i++){
		addedge(en+(i-1)*n,en+i*n);
	}
	dij(st);
	printf("%lld\n",dis[en+k*n]);
	return 0;
}
