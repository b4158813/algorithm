#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
struct node{
	double x,y;
}a[20];
int n;
double ans=inf;
double dis[20][20];
bool vis[1005];
void dfs(int cnt,int now,double sum){
	if(sum>ans) return;
	if(cnt==n){
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(cnt+1,i,sum+dis[now][i]);
			vis[i]=0;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==0){
				dis[i][j]=a[j].x*a[j].x+a[j].y*a[j].y;
				dis[i][j]=sqrt(dis[i][j]);
			}
			dis[i][j]=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
			dis[i][j]=sqrt(dis[i][j]);
		}
	}
	dfs(0,0,0);
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
} 
