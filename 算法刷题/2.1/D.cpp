#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
}a[10005];
int ans,n;
int vis[10005][10005];
int next[10005][10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=10*n;i++){
		for(int j=1;j<=10*n;j++){
			vis[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
//		memset(next,0,sizeof(next));
		for(int j=1;j<=10*n;j++){
			for(int k=1;k<=10*n;k++){
				if(vis[j][k]==0) continue;
				next[j+a[i].x][k+a[i].y]+=vis[j][k];
			}
		}
	}
	for(int i=1;i<=10*n;i++){
		for(int j=1;j<=10*n;j++){
			vis[i][j]+=next[i][j];
		}
	}
	cout<<vis[10*n][10*n]+1;
	return 0;
}
