#include<bits/stdc++.h>
using namespace std;

int n;
int s[35][35];
bool vis[35][35];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

struct node{
	int x,y;
}start,end;

void find(){
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(s[i][j]==1&&s[i+1][j]==1&&s[i][j+1]==1&&s[i+1][j+1]==0){
				start.x=i+1;start.y=j+1;
				return;
			}
		}
	}
}

void bfs(node p1){
	s[p1.x][p1.y]=2;
	node n1,n2;
	queue <node> q;
	q.push(p1);
	while(!q.empty()){
		n1=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			n2=n1;
			n2.x+=dir[i][0];
			n2.y+=dir[i][1];
			if(n2.y<=0||n2.y>n||n2.x<=0||n2.x>n||s[n2.x][n2.y]==1||s[n2.x][n2.y]==2) continue;
			if(s[n2.x][n2.y]==0){
				s[n2.x][n2.y]=2;
			}
			q.push(n2);
		}
	}
	return;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	find();
	bfs(start);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
