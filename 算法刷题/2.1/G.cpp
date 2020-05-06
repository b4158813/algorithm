#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=n;i>=1;i--){
		if(i==1){
			ans+=a[1];
			break;
		}else if(i==2){
			ans+=a[2];
			break;
		}else if(i==3){
			ans+=a[1]+a[2]+a[3];
			break;
		}
		else{
			ans += min(a[1]+2*a[2]+a[i],2*a[1]+a[i-1]+a[i]);
			i--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
