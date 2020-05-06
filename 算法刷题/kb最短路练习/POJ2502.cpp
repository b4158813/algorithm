#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const double inf=1ll<<60;
const double walk=10*1000/60;
const double sub=40*1000/60;

struct Edge{
	int u,v,next;
	double w;
}e[1000005];

int cnt,head[1000005],n,vis[1000005];
double sx,sy,ex,ey;
double dis[1000005];
inline void addedge(int u,int v,double w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline double get_dis(double x1,double y1,double x2,double y2,double speed){
	double dx=x1-x2;
	double dy=y1-y2;
	return sqrt(dx*dx+dy*dy)/speed;
}

struct node{
	double x,y;
}a[1000005];

inline void spfa(int st){
	for(int i=1;i<=n;i++) dis[i]=inf;
	vis[st]=1;
	dis[st]=0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			double w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	scanf("%lf%lf%lf%lf",&sx,&sy,&ex,&ey);
	a[++n]=node{sx,sy};
	n++;
	double x,y;
	while(scanf("%lf%lf",&x,&y)!=EOF){
		double xx,yy;
		a[n]=node{x,y};
		while(~scanf("%lf%lf",&xx,&yy)){
			if(xx==-1&&yy==-1) break;
			a[n+1]=node{xx,yy};
			double Dis=get_dis(x,y,xx,yy,sub);
			addedge(n,n+1,Dis);
			addedge(n+1,n,Dis);
			x=xx,y=yy;
			++n;
		}
		++n;
	}
	a[n]=node{ex,ey};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				double Dis=get_dis(a[i].x,a[i].y,a[j].x,a[j].y,walk);
				addedge(i,j,Dis);
				addedge(j,i,Dis);
			}
		}
	}
	spfa(1);
	printf("%d\n",(int)(dis[n]+0.5));
	return 0;
}
