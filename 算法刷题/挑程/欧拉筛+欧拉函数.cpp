#include<bits/stdc++.h>
using namespace std;
int f[40005],prime[40005],ans[40005],cnt;
int main(){
	int n;
	cin>>n;
	ans[1]=1;
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++){
		if(f[i]==0){
			prime[++cnt]=i;
			ans[i]=i-1;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			f[i*prime[j]]=1;
			if(i%prime[j]==0){
				ans[i*prime[j]]=ans[i]*prime[j];
				break;
			}else{
				ans[i*prime[j]]=ans[i]*ans[prime[j]];
			}
		}
	}
	cout<<ans[n]<<endl;
	return 0;
}
