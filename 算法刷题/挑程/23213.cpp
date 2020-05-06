#include<bits/stdc++.h>
using namespace std;
int ans;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ans+=n/i;
	}
	cout<<ans<<endl;
	return 0;
}
