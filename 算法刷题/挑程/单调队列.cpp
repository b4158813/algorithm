#include<cstdio>
#include<queue>
using namespace std;
int n,k,a[1000005];
deque<int> dq1,dq2;
int ans1[1000005],ans2[1000005];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		while(dq1.size()&&a[i]<a[dq1.back()]){
			dq1.pop_back();
		}
		while(dq2.size()&&a[i]>a[dq2.back()]){
			dq2.pop_back();
		}
		dq1.push_back(i);
		dq2.push_back(i);
		if(dq1.size()>k||dq1.front()<i-k+1) dq1.pop_front();
		if(dq2.size()>k||dq2.front()<i-k+1) dq2.pop_front();
		if(i>=k){
			ans1[i-k+1]=dq1.front();
			ans2[i-k+1]=dq2.front();
		}
	}
	for(int i=1;i<=n-k+1;i++) printf("%d ",a[ans1[i]]);
	printf("\n"); 
	for(int i=1;i<=n-k+1;i++) printf("%d ",a[ans2[i]]);
	return 0;
} 
