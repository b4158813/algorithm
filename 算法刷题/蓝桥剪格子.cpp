#include<bits/stdc++.h>
using namespace std;

int s[15][15],n,m,sum=0,inf=10000,ans;
bool vis[15][15];

void dfs(int x,int y,int cnt,int ssum){
	if(ssum==sum){
		ans=cnt;
		return;
	}
	if(x<=0||x>n||y<=0||y>m||vis[x][y]) return;
	vis[x][y]=1;
	dfs(x+1,y,cnt+1,ssum+s[x][y]);
	dfs(x-1,y,cnt+1,ssum+s[x][y]);
	dfs(x,y+1,cnt+1,ssum+s[x][y]);
	dfs(x,y-1,cnt+1,ssum+s[x][y]);
	vis[x][y]=0;
	return;
}

int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			sum+=s[i][j];
		}
	}
	sum/=2;
	dfs(1,1,0,0);
	ans=min(ans,inf);
	if(ans==inf) cout<<"0"<<endl;
	else cout<<ans<<endl;
	return 0;
}
