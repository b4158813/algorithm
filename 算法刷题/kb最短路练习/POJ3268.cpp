#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
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
struct node{
	int u,dis;
	bool operator<(const node&rhs)const {
		return dis>rhs.dis;
	} 
};
struct Edge{
	int u,v,w,next;
}e1[200005],e2[200005];;

int n,m,x,cnt1,cnt2,head1[200005],head2[200005];
ll dis1[200005],dis2[200005];
inline void addedge1(int u,int v,int w){
	e1[++cnt1].u=u;
	e1[cnt1].v=v;
	e1[cnt1].w=w;
	e1[cnt1].next=head1[u];
	head1[u]=cnt1;
}

inline void addedge2(int u,int v,int w){
	e2[++cnt2].u=u;
	e2[cnt2].v=v;
	e2[cnt2].w=w;
	e2[cnt2].next=head2[u];
	head2[u]=cnt2;
}

inline void dij1(){
	for(int i=1;i<=n;i++) dis1[i]=inf;
	priority_queue<node> q;
	dis1[x]=0;
	q.push(node{x,0});
	while(!q.empty()){
		node q1=q.top();q.pop();
		int u=q1.u;
		if(q1.dis>dis1[u]) continue;
		for(int i=head1[u];i;i=e1[i].next){
			int v=e1[i].v,w=e1[i].w;
			if(dis1[v]>dis1[u]+w){
				dis1[v]=dis1[u]+w;
				q.push(node{v,dis1[v]});
			}
		}
	}
}
inline void dij2(){
	for(int i=1;i<=n;i++) dis2[i]=inf;
	priority_queue<node> q;
	dis2[x]=0;
	q.push(node{x,0});
	while(!q.empty()){
		node q1=q.top();q.pop();
		int u=q1.u;
		if(q1.dis>dis2[u]) continue;
		for(int i=head2[u];i;i=e2[i].next){
			int v=e2[i].v,w=e2[i].w;
			if(dis2[v]>dis2[u]+w){
				dis2[v]=dis2[u]+w;
				q.push(node{v,dis2[v]});
			}
		}
	}
}

int main(){
	n=read();m=read();x=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		addedge1(u,v,w);
		addedge2(v,u,w);
	}
	dij1();
	dij2();
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dis1[i]+dis2[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
