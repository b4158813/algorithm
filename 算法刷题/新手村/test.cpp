#include<bits/stdc++.h>
using namespace std;

int n,ans=0;
//stack<int> s;

void dfs(int x, int y, int cnt){
	if(cnt==n){
		ans++;
		return;
	}
	if(x>0) dfs(x-1,y+1,cnt);
	if(y>0) dfs(x,y-1,cnt+1);
}

int main()
{	
	cin>>n;
	dfs(n,0,0);
	cout<<ans<<endl;
	
	return 0;
}
