#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,a[2000015],ans[2000015];
deque<int> dq;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		while(dq.size()&&a[i]<a[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
		while(dq.size()>m||dq.front()<i-m+1) dq.pop_front();
		ans[i+1]=dq.front();
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[ans[i]]);
	}
	return 0;
}
