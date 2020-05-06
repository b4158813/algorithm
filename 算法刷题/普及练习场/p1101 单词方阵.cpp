#include<bits/stdc++.h>
using namespace std;

map <char,int> m;
int n;
string ss="yizhong";
char s[105][105];
bool vis[105][105];
int dir[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
int v[105][105];

bool in(int x,int y){
	if(x<n&&x>=0&&y<n&&y>=0) return 1;
	else return 0;
}
bool f;

void ranse(int x,int y,int cnt,int k){
	if(cnt<0) return;
	vis[x][y]=1;
	ranse(x-dir[k][0],y-dir[k][1],cnt-1,k);
}
void dfs(int x,int y,int cnt,int k){
	if(cnt==7){
		ranse(x-dir[k][0],y-dir[k][1],cnt-1,k);
		return;
	}
	if(in(x,y)&&s[x][y]==ss[cnt]){
		dfs(x+dir[k][0],y+dir[k][1],cnt+1,k);
	}else return;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	vis[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]=='y'){
				for(int u=0;u<8;u++)
				dfs(i,j,0,u);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vis[i][j]) cout<<s[i][j];
			else cout<<"*"; 
		}
		cout<<endl;
	}
	return 0;
}
