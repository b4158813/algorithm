#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q; 

int main(){
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		q.push(a);
	}
	int sum=0,m=0;
	while(q.size()>1){
		sum=0;
		int a=q.top();
		q.pop();
		int b=q.top();
		q.pop();
		sum+=a+b;
		m+=sum;
		q.push(sum);
	}
	cout<<m<<endl;
	return 0;
}
