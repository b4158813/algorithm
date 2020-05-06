#include<iostream>
#include<algorithm>
#include<queue> 
#include<cstring>
using namespace std;
typedef long long ll;
const int inf = 2147483647;
struct Edge{
	int u,v,w,next;
}e[1000005];

struct node{
	int u,dis;
	bool operator <(const node&rhs)const{
		return dis>rhs.dis;
	}
};

int n,s,ans,cnt,now,head[1000005],dis[1000005];
inline void addedge(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
inline void dijkstra(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	priority_queue<node> q;
	dis[1]=0;
	q.push((node){1,0});
	while(!q.empty()){
		node q1=q.top();
		q.pop();
		int u=q1.u;
		if(q1.dis>dis[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push((node){v,dis[v]});
			}
		}
	}
}

inline int Stoi(string s){
	int ans=0;
	for(int i=s.length()-1,j=1;i>=0;i--,j*=10){
		ans+=(s[i]-'0')*j;
	}
	return ans;
} 

int main(){
	cin>>n;
	string x;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			cin>>x;
			if(x=="x") continue;
			int w=Stoi(x);
			addedge(i,j,w);
			addedge(j,i,w);
		}
	}

	dijkstra();
	int ans=0;
	for(int i=2;i<=n;i++){
		ans=max(ans,dis[i]);
	}
	cout<<ans<<endl;
	return 0;
}
