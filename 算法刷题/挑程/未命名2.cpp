#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
int main(){
	int n;
	int t=0;
	while(cin>>n&&n){
		if(t>=1)cout<<endl;
		t++;
		memset(a,0,sizeof(a));
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		int avg=sum/n;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]<avg) ans+=avg-a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
