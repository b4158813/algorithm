#include<bits/stdc++.h>
using namespace std;
int n,d;
int main(){
	cin>>n>>d;
	vector<int> vec;
	while(n){
		vec.push_back(n%d);
		n/=d;
	}
	bool f=true;
	int len=vec.size();
	for(int i=0;i<len;i++){
		if(vec[i]!=vec[len-i-1]){
			f=0;
			break;
		}
	}
	if(f) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(int i=len-1;i>0;i--){
		cout<<vec[i]<<" ";
	}
	cout<<vec[0];
	return 0;

}