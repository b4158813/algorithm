#include<iostream>
using namespace std;
int n,a[100005];

int main(){
	cin>>n;
	bool f=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0) f=true;
	}
	if(!f){
		cout<<0<<" "<<a[1]<<" "<<a[n];
		return 0;
	}
	long long sum=0,ansz=1,ansy=1,ans=-1ll<<60;
	int zuo=1,you=1;
	while(zuo<=n&&you<=n){
		sum+=a[you];
		if(sum>ans){
			ans=sum;
			ansz=zuo,ansy=you;
		}
		if(sum<0){
			sum=0;
			zuo=you+1;
		}
		you++;
	}
	cout<<ans<<" "<<a[ansz]<<" "<<a[ansy];
	return 0;
}