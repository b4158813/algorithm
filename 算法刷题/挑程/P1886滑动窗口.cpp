#include<bits/stdc++.h>
using namespace std;
deque<int> q1;
deque<int> q2;
int a[1000005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		while(!q2.empty()&&a[i]<a[q2.back()]){
			q2.pop_back();
		}
		q2.push_back(i);
		if(i-k+1>q2.front()) q2.pop_front();
		if(i>=k) cout<<a[q2.front()]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		while(!q1.empty()&&a[i]>=a[q1.back()]){
			q1.pop_back();
		}
		q1.push_back(i);
		if(i-k+1>q1.front()) q1.pop_front();
		if(i>=k) cout<<a[q1.front()]<<" ";
	}
	return 0;
} //https://www.luogu.com.cn/problem/P1886
