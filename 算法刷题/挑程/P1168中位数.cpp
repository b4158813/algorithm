#include<bits/stdc++.h>
using namespace std;
vector<int> a; 
int main(){
    int n,x;
    cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(!a.empty()){
			int pos = lower_bound(a.begin(),a.end(),x)-a.begin();
			a.insert(a.begin()+pos,x);
		//	cout<<pos<<" ";	
		}else a.push_back(x);
		if((i+1)%2==1) cout<<a[(i+1)/2]<<endl;
	}
	return 0;
}
