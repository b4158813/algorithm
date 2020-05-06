#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=2147483647;
struct Edge{
	ll u,v,w,next;
}e1[600005],e2[600005];

struct node{
	ll u,dis;
	bool operator<(const node&rhs)const{
		return dis>rhs.dis;
	}
};

int n,m;
ll cnt1,cnt2,head1[10000005],head2[10000005];
inline void addedge1(ll u,ll v,ll w){
	e1[++cnt1].u=u;
	e1[cnt1].v=v;
	e1[cnt1].w=w;
	e1[cnt1].next=head1[u];
	head1[u]=cnt1;
}

inline void addedge2(ll u,ll v,ll w){
	e2[++cnt2].u=u;
	e2[cnt2].v=v;
	e2[cnt2].w=w;
	e2[cnt2].next=head2[u];
	head2[u]=cnt2;
}
ll dis1[100005],dis2[100005];
inline void spfa1(){
	for(int i=1;i<=n;i++){
		dis1[i]=inf;
	}
	priority_queue<node> q;
	dis1[1]=0;
	q.push(node{1,0});
	while(!q.empty()){
		node q1=q.top();
		q.pop();
		ll u=q1.u,d=q1.dis;
		if(d>dis1[u]) continue;
		for(int i=head1[u];i;i=e1[i].next){
			ll v=e1[i].v,w=e1[i].w;
			if(dis1[v]>dis1[u]+w){
				dis1[v]=dis1[u]+w;
				q.push(node{v,dis1[v]});
			}
		}
	}
}
inline void spfa2(){
	for(int i=1;i<=n;i++){
		dis2[i]=inf;
	}
	priority_queue<node> q;
	dis2[1]=0;
	q.push(node{1,0});
	while(!q.empty()){
		node q1=q.top();
		q.pop();
		ll u=q1.u,d=q1.dis;
		if(d>dis2[u]) continue;
		for(int i=head2[u];i;i=e2[i].next){
			ll v=e2[i].v,w=e2[i].w;
			if(dis2[v]>dis2[u]+w){
				dis2[v]=dis2[u]+w;
				q.push(node{v,dis2[v]});
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(head1,0,sizeof(head1));
		memset(head2,0,sizeof(head2));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(u==v) continue;
			addedge1(u,v,w);
			addedge2(v,u,w);
		}
		spfa1();
		spfa2();
	//	ll maxdis=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
	//		maxdis=max(maxdis,dis2[i]);
			ans+=dis1[i]+dis2[i];
		}
	//	ans-=maxdis;
		cout<<ans<<endl;
	}
	return 0;
}
