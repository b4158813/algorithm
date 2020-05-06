#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=2147483647;
struct Edge{
	int u,v,w,next;
}e[100005];

ll cnt,n,m,b,f[100005],te[100005];
ll dis[100005],vis[100005],head[100005];

inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline bool check(int maxx){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=inf;
	queue<int> q;
	vis[1]=1;
	dis[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w&&f[v]<=maxx){
				dis[v]=dis[u]+w;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	
	if(dis[n]<=b) return true;
	else return false;
}

int main(){
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		te[i]=f[i];
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u==v) continue;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	sort(te+1,te+1+n);
	
	if(!check(1e9)){
		cout<<"AFK"<<endl;
		return 0;
	}
	
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(te[mid])){
			r=mid-1;
			ans=te[mid];
		}
		else l=mid+1; 
	}
	cout<<ans<<endl;
	return 0;
}
