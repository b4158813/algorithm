#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
struct Edge{
	int u,v,w,next;
}e1[1000005],e2[1000005];

int n,m,s=1,cnt1,cnt2,head1[1000005],head2[1000005],jia[1000005];
inline void addedge1(int u,int v,int w){
	e1[++cnt1].u=u;
	e1[cnt1].v=v;
	e1[cnt1].w=w;
	e1[cnt1].next=head1[u];
	head1[u]=cnt1;
}
int dis1[1000005],dis2[1000005],vis1[1000005],vis2[1000005];
inline void addedge2(int u,int v,int w){
	e2[++cnt2].u=u;
	e2[cnt2].v=v;
	e2[cnt2].w=w;
	e2[cnt2].next=head2[u];
	head2[u]=cnt2;
}

inline void spfa1(){
	memset(vis1,0,sizeof(vis1));
	for(int i=1;i<=n;i++) dis1[i]=inf;
	vis1[1]=1;
	dis1[1]=jia[1];
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis1[u]=0;
		dis1[u]=min(dis1[u],jia[u]);
		for(int i=head1[u];i;i=e1[i].next){
			int v=e1[i].v;
			if(dis1[v]>dis1[u]){
				dis1[v]=dis1[u];
				if(vis1[v]==0){
					vis1[v]=1;
					q.push(v);
				}
			}
		}
	}
}

inline void spfa2(){
	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=n;i++) dis2[i]=0;
	vis2[n]=1;
	dis2[n]=jia[n];
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis2[u]=0;
		dis2[u]=max(dis2[u],jia[u]);
		for(int i=head2[u];i;i=e2[i].next){
			int v=e2[i].v;
			if(dis2[v]<dis2[u]){
				dis2[v]=dis2[u];
				if(vis2[v]==0){
					vis2[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>jia[i];
	for(int i=1;i<=m;i++){
		int u,v,z;
		cin>>u>>v>>z;
		addedge1(u,v,1);
		addedge2(v,u,1);
		if(z==2){
			addedge1(v,u,1);
			addedge2(u,v,1);
		}
	}
	
	spfa1();
	spfa2();
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=max(sum,dis2[i]-dis1[i]);
	}
	cout<<sum<<endl;
	return 0;
}//https://www.luogu.com.cn/problem/P1073

