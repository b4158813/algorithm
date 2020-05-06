#include<bits/stdc++.h>
using namespace std;

int n,a;
vector<int> ans;

int main(){
	cin>>n;
	ans.push_back(0);
	int b=1;
	for(int i=0;i<n;i++){
		for(int j=ans.size()-1;j>=0;j--){
			ans.push_back(ans[j]+b);
		}
		b=b<<1;
	} 
	vector<int>::iterator iter;
	for(iter=ans.begin();iter!=ans.end();iter++){
		cout<<*iter;
		if(iter==ans.end()-1)break;
		else cout<<" ";
	}
	return 0;
}
