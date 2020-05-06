#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> gg[50005];
int main(){
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		gg[u].push_back(v);
		gg[v].push_back(u);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int temp=0;
		int Size=gg[i].size();
		for(int i=0;i<Size;i++){
			temp++;
		}
		if(temp%2!=0){
			ans++;
		}
	}
	if(ans==0||ans==2) cout<<"Full"<<endl;
	else cout<<"Part"<<endl;
	return 0;
}
