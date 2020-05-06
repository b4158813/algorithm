#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d",&x);
		if(x==1){
			scanf("%d",&y);
			q.push(y);
			continue;
		}
		if(x==2){
			cout<<q.top()<<endl;
			continue;
		}
		if(x==3){
			q.pop();
			continue;
		}
	}
	return 0;
}
