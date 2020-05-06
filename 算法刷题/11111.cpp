#include<bits/stdc++.h>
using namespace std;
int f[10005],n;
int a[10005],ans[10005];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			f[a[i]]=1;
		}
		if(f[1]==0||f[2*n]==1){
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			ans[2*i-1]=a[i];
			++cnt;
			for(int j=a[i];j<=2*n;j++){
				if(f[j]==1)continue;
				ans[2*i]=j;
				++cnt;
				f[j]=1;
				break;
			}
		}
		if(cnt<2*n){
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=1;i<=2*n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
