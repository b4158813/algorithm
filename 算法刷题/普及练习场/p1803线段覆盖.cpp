#include<bits/stdc++.h>
using namespace std;

struct p{
	int left,right;
}test[1000005];

bool cmp(p t1,p t2){
	return t1.right<t2.right;
}

int main(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>test[i].left>>test[i].right;
	}
	sort(test+1,test+n+1,cmp);
	ans++;
	int p=1;
	for(int i=2;i<=n;i++){
		if(test[p].right<=test[i].left){
			ans++;p=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
