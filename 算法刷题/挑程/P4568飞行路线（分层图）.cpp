#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
struct Edge{
	int u,v,w,next;
}e[500005];

struct node{
	int u,w;
	bool operator<(const node&rhs)const{
		return w>rhs.w;
	}
};

int n,m,k,s,t,cnt,head[1000005],dis[1000005][25];

inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dijkstra(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++){
			dis[i][j]=inf;
		}
	}
	for(int i=0;i<=k;i++) dis[s][i]=0;
	priority_queue<node> q;
	for(int i=0;i<=k;i++){
		q.push((node){s,0});
		while(!q.empty()){
			node q1=q.top();
			q.pop();
			int u=q1.u;
			if(q1.w>dis[u][i])continue;
			for(int p=head[u];p;p=e[p].next){
				int v=e[p].v,w=e[p].w;
				bool f=false;
				if(dis[v][i]>dis[u][i]+w){
					dis[v][i]=dis[u][i]+w;
					f=true;
				}
				if(i>0&&dis[v][i]>dis[u][i-1]){
					dis[v][i]=dis[u][i-1];
					f=true;
				}
				if(f){
					q.push((node){v,dis[v][i]});
				}
			}
		}
	}
	
	
}

int main(){
	cin>>n>>m>>k>>s>>t;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	} 
	dijkstra();
	cout<<dis[t][k]<<endl;
	return 0; 
}
