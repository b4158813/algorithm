#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int ,int> P;
int n,m;
char s[12][12];
int ans;
int nn,vis[15][15];
const int inf = 1<<30;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int d[15][15];
P no[105];

int bfs(P p1,P p2){
	queue <P> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			d[i][j]=inf;
		}
	}
	memset(vis,0,sizeof(vis));
	q.push(p1);
	q.push(p2);
	d[p1.first][p1.second]=0;
	d[p2.first][p2.second]=0;
	vis[p1.first][p1.second]=1;
	vis[p2.first][p2.second]=1;
	P temp;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int dx=dir[i][0]+temp.first;
			int dy=dir[i][1]+temp.second;
			if(!vis[dx][dy]&&s[dx][dy]!='.'&&dx>=0&&dx<n&&dy>=0&&dy<m){
				vis[dx][dy]=1;
				q.push(P(dx,dy));
				d[dx][dy]=d[temp.first][temp.second]+1;
			}
		}
	}
	for(int i=0;i<nn;++i){
		if(d[no[i].first][no[i].second]==inf) 
			return inf;
	}
	return d[temp.first][temp.second];
}

int main(){
	int t;
	cin>>t;
	for(int u=1;u<=t;u++){
		cin>>n>>m;
		int ans=inf;
		nn=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>s[i][j];
				if(s[i][j]=='#'){
					no[nn].first=i,no[nn++].second=j;
				}
			}
		}
		printf("Case %d: ",u);
		if(nn<=1){
			cout<<"0"<<endl;continue;
		}
		for(int i=0;i<nn;++i){
			for(int j=i+1;j<nn;++j){
				ans=min(ans,bfs(no[i],no[j]));
			}
		}
		if(ans!=inf) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
