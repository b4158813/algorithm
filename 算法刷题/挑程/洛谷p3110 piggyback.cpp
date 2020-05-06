#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
struct Edge{
	int u,v,w,next;
}e1[100005],e2[100005],e3[100005];

int cnt1,cnt2,cnt3,dis1[100005],dis2[100005],dis3[100005];
int head1[100005],head2[100005],head3[100005];
int b,e,p,n,m,vis1[100005],vis2[100005],vis3[100005];
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
inline void addedge3(int u,int v,int w){
	e3[++cnt3].u=u;
	e3[cnt3].v=v;
	e3[cnt3].w=w;
	e3[cnt3].next=head3[u];
	head3[u]=cnt3;
}

inline void dij1(){
	for(int i=1;i<=n;i++) dis1[i]=inf;
	queue<int> q;
	dis1[1]=0;
	vis1[1]=1;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis1[u]=0;
		for(int i=head1[u];i;i=e1[i].next){
			int v=e1[i].v,w=e1[i].w;
			if(dis1[v]>dis1[u]+w){
				dis1[v]=dis1[u]+w;
				if(vis1[v]==0){
					vis1[v]=1;
					q.push(v);
				}
			}
		}
	}
}
inline void dij2(){
	for(int i=1;i<=n;i++) dis2[i]=inf;
	queue<int> q;
	dis2[2]=0;
	vis2[2]=1;
	q.push(2);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis2[u]=0;
		for(int i=head2[u];i;i=e2[i].next){
			int v=e2[i].v,w=e2[i].w;
			if(dis2[v]>dis2[u]+w){
				dis2[v]=dis2[u]+w;
				if(vis2[v]==0){
					vis2[v]=1;
					q.push(v);
				}
			}
		}
	}
}
inline void dij3(){
	for(int i=1;i<=n;i++) dis3[i]=inf;
	queue<int> q;
	dis3[n]=0;
	vis3[n]=1;
	q.push(n);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis3[u]=0;
		for(int i=head3[u];i;i=e3[i].next){
			int v=e3[i].v,w=e3[i].w;
			if(dis3[v]>dis3[u]+w){
				dis3[v]=dis3[u]+w;
				if(vis3[v]==0){
					vis3[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	cin>>b>>e>>p>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		addedge1(u,v,b);
		addedge1(v,u,b);
		addedge2(u,v,e);
		addedge2(v,u,e);
		addedge3(u,v,p);
		addedge3(v,u,p);
	}
	dij1();dij2();dij3();
	int ans=inf;
	for(int i=1;i<=n;i++){
		ans=min(ans,dis1[i]+dis2[i]+dis3[i]);
	}
	cout<<ans<<endl;
	return 0;
}
