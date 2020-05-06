#include<bits/stdc++.h>
using namespace std;
int a[3000005],sta[3000005],ans[3000006];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int top=0;
	
	for(int i=n;i>=1;i--){
		while(top>0&&a[i]>=a[sta[top]]) --top;
		ans[i]=sta[top];
		sta[++top]=i;
	}
	
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
