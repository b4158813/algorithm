#include<bits/stdc++.h>
using namespace std;
vector<int> vec1,vec2;
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		char c;
		cin>>c;
		if(c=='D'){
			int x;
			cin>>x;
			vec1.push_back(x);
		}
		if(c=='Q'){
			int x;
			cin>>x;
			vec2.assign(vec1.begin(),vec1.end());
			sort(vec2.begin(),vec2.end());
			vector<int>::iterator it;
			int pos=0,end=n;
			bool f=true;
			for(it=vec2.begin();it!=vec2.end();it++){
				if((*it)==x){
					cout<<0<<endl;
					f=false;
					break;
				}else if((*it)>x){
					cout<<*it-pos-1<<endl;
					f=false;
					break;
				}pos=*it;
			}
			if(f) cout<<end-pos<<endl;
		}
		if(c=='R'){
			vec1.pop_back();
		}
	}
	return 0;
}
