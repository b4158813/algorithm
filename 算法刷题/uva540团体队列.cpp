#include<bits/stdc++.h>
using namespace std;

map <int,int> team;

int main(){
	int t,th=0;
	while(cin>>t&&t){
		cout<<"Scenario #"<<++th<<endl;
		for(int i=0;i<t;i++){
			int k;
			cin>>k;
			for(int j=0;j<k;j++){
				int id;
				cin>>id;
				team[id]=i;
			}
		}
		queue <int> q,qp[1005]; 
	while(1){
		string op;
		cin>>op;
		if(op=="ENQUEUE"){
			int x;
			cin>>x;
			if(qp[team[x]].empty()){
				q.push(team[x]);
				qp[team[x]].push(x);
			}
			else qp[team[x]].push(x);
		}
		if(op=="DEQUEUE"){
			cout<<qp[q.front()].front()<<endl;
			qp[q.front()].pop();
			if(qp[q.front()].empty()) q.pop();
		}
		if(op=="STOP"){
			cout<<endl;
			break;
		}
	}
	}
	return 0;
}
