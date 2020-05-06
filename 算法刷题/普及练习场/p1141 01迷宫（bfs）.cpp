#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[1005][1005];
int vis[1005][1005];
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int ans;

struct node{
	int x,y;
}start;

void bfs(){
	queue <node> q;
	node a;
	a.x=start.x;
	a.y=start.y;
	vis[a.x][a.y]=1;
	q.push(a);
	while(!q.empty()){
		a=q.front();
		q.pop();
		if(s[a.x][a.y]=='0'){
			if(vis[a.x][a.y]) break;
			for(int i=0;i<4;i++){
				node next;
				next=a;
				next.x+=dir[i][0];
				next.y+=dir[i][1];
				if(next.x<=0||next.y<=0||next.x>n||next.y>n) continue;
				if(s[next.x][next.y]=='1'){
					ans++;
					vis[next.x][next.y]=1;
					q.push(next);
				}
			}
		}
		if(s[a.x][a.y]=='1'){
			if(vis[a.x][a.y]) break;
			for(int i=0;i<4;i++){
				node next;
				next=a;
				next.x+=dir[i][0];
				next.y+=dir[i][1];
				if(next.x<=0||next.y<=0||next.x>n||next.y>n) continue;
				if(s[next.x][next.y]=='0'){
					ans++;
					vis[next.x][next.y]=1;
					q.push(next);
				}
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	while(m--){
		cin>>start.x>>start.y;
		ans=0;
		memset(vis,0,sizeof(vis));
		bfs();
		cout<<ans<<endl;
	}
	return 0;
}
