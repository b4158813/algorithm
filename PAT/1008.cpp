#include<iostream>
using namespace std;
int n,x,ans;
int main(){
	cin>>n;
	int cur=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x>cur) ans+=5+(x-cur)*6;
		if(x<cur) ans+=5+(cur-x)*4;
		if(x==cur) ans+=5;
		cur=x;
	}
	cout<<ans;
	return 0;
}