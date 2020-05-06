#include<bits/stdc++.h>
using namespace std;

queue <int> q;//开一个队列 

int main(){
	int n;
	while(cin>>n&&n){
		if(n==1){//输入是1的时候的调整 
			cout<<"Discarded cards:\nRemaining card: 1\n";
			continue;
		}
		if(!q.empty()) q.pop();//如果不空，则pop一个（因为每次循环后只剩最后一个） 
		int i=0;
		while(n--){
			q.push(++i);//填入数字 
		}
		cout<<"Discarded cards: ";
		for(;;){
			cout<<q.front();//输出顶部一个 
			q.pop();//pop掉顶部那一个 
			q.push(q.front());//把顶部一个push到尾部 
			q.pop();//pop掉顶部那一个 
			if(q.size()==1) {//如果只剩 1 个了 
				cout<<endl;break;
			}
			cout<<", ";//控制逗号输出 
		}
		cout<<"Remaining card: "<<q.front()<<endl;
	}
	return 0;
}
