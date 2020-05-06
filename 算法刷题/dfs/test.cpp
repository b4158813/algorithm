#include<bits/stdc++.h>
using namespace std;
const int maxn = 50;
int n,x[maxn],y[maxn],xy[maxn],yx[maxn];
int ans;
int cnt=0;
void dfs(int k){
	if(k>n){
		if(cnt<=2){
			for(int j=1;j<=n;j++){
				cout<<x[j]<<" ";
			}
			cout<<endl;
			cnt++;
		}
		ans++;
	}
	for(int i=1;i<=n;i++){
		if(!y[i]&&!xy[i+k]&&!yx[i-k+n]){
			x[k]=i;
			y[i]=1;
			xy[i+k]=1;
			yx[i-k+n]=1;
			dfs(k+1);
			y[i]=0;
			xy[i+k]=0;
			yx[i-k+n]=0;
		}
	}
}

int main(){
	cin>>n;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
