#include<cstring>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int n,k;
int vis[1000005];
int ans;

struct node{
	int x,step;
}start,end;

void bfs(){
	memset(vis,0,sizeof(vis));
	int dx[3];
	queue <node> q;
	node hh;
	hh.x=start.x;
	hh.step=0;
	q.push(hh);
	while(!q.empty()){
		node q1=q.front();
		q.pop();
//		if(end.x==start.x){
//			ans=2;
//			return;
//		}
		if(q1.x==end.x){
			ans=q1.step;
			return;
		}
		dx[0]=q1.x+1;
		dx[1]=q1.x-1;
		dx[2]=q1.x*2;
		for(int i=0;i<3;i++){
			if(vis[dx[i]]==0&&dx[i]>=0&&dx[i]<=100000){
				vis[dx[i]]=1;
				node v;
				v.step=q1.step+1;
				v.x=dx[i];
				q.push(v);
			}
		}
		
	}
}

int main(){
	while(cin>>n>>k){
//	cin>>n>>k;
	start.x=n;
	end.x=k;
	ans=0;
	bfs();
	cout<<ans<<endl;
	}
	return 0;
}
