#include<bits/stdc++.h>
using namespace std;

int n,m,k,qq,ans[155],cnt;
struct node
{
	int id,t;
}a[105];
queue<node> q[155];

inline void solve(int x){
	if(!ans[x]){
		printf("Sorry\n");
		return;
	}
	int mm=ans[x]%60;
	int hh=ans[x]/60;
	printf("%02d:%02d\n",8+hh,mm);
	return;
}
int main(){
	cin>>n>>m>>k>>qq;
	for(int i=1;i<=k;i++){
		cin>>a[i].t;
		a[i].id=i;
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			q[i].push(node{a[++cnt].id,a[cnt].t});
		}
	}
	for(int pe=1;pe<=540;pe++){
		for(int i=1;i<=n;i++){
			if(--q[i].front().t==0){
				ans[q[i].front().id]=pe;
				q[i].pop();
				q[i].push(node{a[++cnt].id,a[cnt].t});
			}
		}
	}
	// for(int i=1;i<=k;i++) cout<<ans[i]<<" ";
	for(int i=1;i<=qq;i++){
		int x;
		cin>>x;
		solve(x);
	}
	return 0;
}