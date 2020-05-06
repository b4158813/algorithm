#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	int t=1;
	while(!q.empty()){
		if(t==m){
			cout<<q.front()<<" ";
			q.pop();
			t=1;
		}
		t++;
		int x=q.front();
		q.push(x);
		q.pop();
	}
	return 0;
}
