#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
int n,t;
struct Edge{
	int u,v,next;
	double w;
}e[4005];
int cnt,head[4005];
inline void addedge(int u,int v,double w){
	e[++cnt]=Edge{u,v,head[u],w};
	head[u]=cnt;
}
int vis[4005],ring[4005];
double dis[4005];
inline bool spfa(int st){
	memset(vis,0,sizeof(vis));
	memset(dis,1,sizeof(dis));
	memset(ring,0,sizeof(ring));
	queue<int> q;
	vis[st]=1;
	ring[st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			double w=e[i].w;
			if(dis[v]<dis[u]*w){
				dis[v]=dis[u]*w;
				ring[v]=ring[u]+1;
				if(ring[v]>n) return true;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int ccnt=0;
	while(cin>>n&&n){
		cnt=0;
		memset(head,0,sizeof(head));
		map<string,int> ma;
		string s,ss;
		for(int i=1;i<=n;i++){
			cin>>s;
			ma[s]=i;
		}
		cin>>t;
		double giao;
		for(int i=1;i<=t;i++){
			cin>>s>>giao>>ss;
			addedge(ma[s],ma[ss],giao);
		}
		cout<<"Case "<<++ccnt<<": ";
		bool f=false;
		for(int i=1;i<=n;i++){
			if(f) break;
			if(spfa(i)){
				f=true;
			}
		}
		if(f) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
