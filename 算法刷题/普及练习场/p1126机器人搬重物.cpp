#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[55][55];
int vis[55][55];
int sx,sy,ex,ey;
char c;
int ans=0;
bool f;

struct node{
	int x,y,step;
	char c;
}start,end;

bool in(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return 0;
	return 1;
}


void bfs(){
	f=false;
	queue <node> q;
	node ss;
	ss.x=start.x;
	ss.y=start.y;
	ss.c=start.c;
	ss.step=0;
	q.push(ss);
	while(!q.empty()){
		node q1=q.front();
		q.pop();
		if(s[q1.x][q1.y]==1) continue;
		if(q1.x==end.x&&q1.y==end.y){
			f=true;
			ans=q1.step;
			return;
		}
		if('S'==q1.c){
			node v1;
			v1.c='S';
			v1.step=q1.step+1;
			v1.x=q1.x+1;
			v1.y=q1.y;
			if(in(v1.x,v1.y)&&s[q1.x][q1.y]!=1) q.push(v1);
			
			node v2;
			v2.c='S';
			v2.step=q1.step+1;
			v2.x=q1.x+2;
			v2.y=q1.y;
			if(in(v2.x,v2.y)&&s[q1.x-1][q1.y]!=1&&s[q1.x][q1.y]!=1)q.push(v2);
			
			node v3;
			v3.c='S';
			v3.step=q1.step+1;
			v3.x=q1.x+3;
			v3.y=q1.y;
			if(in(v3.x,v3.y)&&s[q1.x-2][q1.y]!=1&&s[q1.x-1][q1.y]!=1&&s[q1.x][q1.y]!=1)q.push(v3);
			
			node v4;
			v4.c='W';
			v4.step=q1.step+1;
			v4.x=q1.x;
			v4.y=q1.y;
			if(in(v4.x,v4.y))q.push(v4);
			
			node v5;
			v5.c='E';
			v5.step=q1.step+1;
			v5.x=q1.x;
			v5.y=q1.y;
			if(in(v5.x,v5.y))q.push(v5);
		}
		else if('W'==q1.c){
			node v1;
			v1.c='W';
			v1.step=q1.step+1;
			v1.x=q1.x;
			v1.y=q1.y-1;
			if(in(v1.x,v1.y)&&s[q1.x][q1.y]!=1) q.push(v1);
			
			node v2;
			v2.c='W';
			v2.step=q1.step+1;
			v2.x=q1.x;
			v2.y=q1.y-2;
			if(in(v2.x,v2.y)&&s[q1.x][q1.y+1]!=1&&s[q1.x][q1.y]!=1)q.push(v2);
			
			node v3;
			v3.c='W';
			v3.step=q1.step+1;
			v3.x=q1.x;
			v3.y=q1.y-3;
			if(in(v3.x,v3.y)&&s[q1.x][q1.y+2]!=1&&s[q1.x][q1.y+1]!=1&&s[q1.x][q1.y]!=1)q.push(v3);
			
			node v4;
			v4.c='N';
			v4.step=q1.step+1;
			v4.x=q1.x;
			v4.y=q1.y;
			if(in(v4.x,v4.y))q.push(v4);
			
			node v5;
			v5.c='S';
			v5.step=q1.step+1;
			v5.x=q1.x;
			v5.y=q1.y;
			if(in(v5.x,v5.y))q.push(v5);
		}
		else if('E'==q1.c){
			node v1;
			v1.c='E';
			v1.step=q1.step+1;
			v1.x=q1.x;
			v1.y=q1.y+1;
			if(in(v1.x,v1.y)&&s[q1.x][q1.y]!=1) q.push(v1);
			
			node v2;
			v2.c='E';
			v2.step=q1.step+1;
			v2.x=q1.x;
			v2.y=q1.y+2;
			if(in(v2.x,v2.y)&&s[q1.x][q1.y-1]!=1&&s[q1.x][q1.y]!=1)q.push(v2);
			
			node v3;
			v3.c='E';
			v3.step=q1.step+1;
			v3.x=q1.x;
			v3.y=q1.y+3;
			if(in(v3.x,v3.y)&&s[q1.x][q1.y-2]!=1&&s[q1.x][q1.y-1]!=1&&s[q1.x][q1.y]!=1)q.push(v3);
			
			node v4;
			v4.c='N';
			v4.step=q1.step+1;
			v4.x=q1.x;
			v4.y=q1.y;
			if(in(v4.x,v4.y))q.push(v4);
			
			node v5;
			v5.c='S';
			v5.step=q1.step+1;
			v5.x=q1.x;
			v5.y=q1.y;
			if(in(v5.x,v5.y))q.push(v5);
		}
		else if('N'==q1.c){
			node v1;
			v1.c='N';
			v1.step=q1.step+1;
			v1.x=q1.x-1;
			v1.y=q1.y;
			if(in(v1.x,v1.y)&&s[q1.x][q1.y]!=1) q.push(v1);
			
			node v2;
			v2.c='N';
			v2.step=q1.step+1;
			v2.x=q1.x-2;
			v2.y=q1.y;
			if(in(v2.x,v2.y)&&s[q1.x+1][q1.y]!=1&&s[q1.x][q1.y]!=1)q.push(v2);
			
			node v3;
			v3.c='N';
			v3.step=q1.step+1;
			v3.x=q1.x-3;
			v3.y=q1.y;
			if(in(v3.x,v3.y)&&s[q1.x+2][q1.y]!=1&&s[q1.x+1][q1.y]!=1&&s[q1.x][q1.y]!=1)q.push(v3);
			
			node v4;
			v4.c='W';
			v4.step=q1.step+1;
			v4.x=q1.x;
			v4.y=q1.y;
			if(in(v4.x,v4.y))q.push(v4);
			
			node v5;
			v5.c='E';
			v5.step=q1.step+1;
			v5.x=q1.x;
			v5.y=q1.y;
			if(in(v5.x,v5.y))q.push(v5);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s[i][j];
		}
	}
	cin>>sx>>sy>>ex>>ey>>c;
	start.x=sx;start.y=sy;start.c=c;end.x=ex;end.y=ey;
	bfs();
	if(f) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	return 0;
}
