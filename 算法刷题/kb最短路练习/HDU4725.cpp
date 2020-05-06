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
int cnt,head[800005];
ll dis[800005];
int n,m,c;
struct Edge{
	int u,v,w,next;
}e[800005]; 
struct node{
	int u,dis;
	bool operator<(const node&rhs)const {
		return dis>rhs.dis;
	}
};

inline void addedge(int u,int v,int w){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}

inline void dij(){
	for(int i=1;i<=(n+n);i++) dis[i]=inf;
	dis[1]=0;
	priority_queue<node> q;
	q.push(node{1,0});
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
	int t=read();
	for(int o=1;o<=t;o++){
		cnt=0;
		memset(head,0,sizeof(head));
		memset(e,0,sizeof(e)); 
		n=read(),m=read(),c=read();
		int x,y,z;
		for(int i=1;i<=n;i++){
			x=read();
			addedge(i,n+x,0);
			if(x>1){
				addedge(i,n+x-1,c);
				addedge(n+x-1,i,c);
			}
			if(x<n){
				addedge(i,n+x+1,c);
				addedge(n+x+1,i,c);
			}
		}
		for(int i=1;i<=m;i++){
			x=read(),y=read(),z=read();
			addedge(x,y,z);
			addedge(y,x,z);
		}
		dij();
		printf("Case #%d: %lld\n",o,dis[n]==inf?-1:dis[n]);
	}
	return 0;
}
