#include<bits/stdc++.h>
using namespace std;

queue <int> q;//��һ������ 

int main(){
	int n;
	while(cin>>n&&n){
		if(n==1){//������1��ʱ��ĵ��� 
			cout<<"Discarded cards:\nRemaining card: 1\n";
			continue;
		}
		if(!q.empty()) q.pop();//������գ���popһ������Ϊÿ��ѭ����ֻʣ���һ���� 
		int i=0;
		while(n--){
			q.push(++i);//�������� 
		}
		cout<<"Discarded cards: ";
		for(;;){
			cout<<q.front();//�������һ�� 
			q.pop();//pop��������һ�� 
			q.push(q.front());//�Ѷ���һ��push��β�� 
			q.pop();//pop��������һ�� 
			if(q.size()==1) {//���ֻʣ 1 ���� 
				cout<<endl;break;
			}
			cout<<", ";//���ƶ������ 
		}
		cout<<"Remaining card: "<<q.front()<<endl;
	}
	return 0;
}
