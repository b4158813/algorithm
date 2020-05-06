#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
struct Edge{
	int u,v,w,next;
}e[1000005];

struct node{
	int u,dis;
	bool operator<(const node& rhs)const{
		return dis>rhs.dis;
	}
};

int n,s=1,cnt,head[1000005],pre[1000005],ans[1000005];
inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int dis[1000005];
inline void dijkstra(){
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	}
	priority_queue<node> q;
	dis[s]=0;
	q.push(node{s,0});
	while(!q.empty()){
		node q1=q.top();
		q.pop();
		int u=q1.u,d=q1.dis;
		if(d>dis[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pre[v]=u;
				q.push(node{v,dis[v]});
			}
		}
	}
	int t=0;
	for(int i=n;i;i=pre[i]){
		ans[++t]=i;
	}
	for(int i=t;i>=1;i--) cout<<ans[i]<<" ";
}


int main(){
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>x;
			if(x!=0) addedge(i,j,x);
		}
	}
	dijkstra();
	cout<<endl;
	cout<<dis[n]<<endl;
	return 0;
	
}//https://vijos.org/p/1635
