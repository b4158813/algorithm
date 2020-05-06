#include<bits/stdc++.h>
using namespace std;
int ans,n,m,a[100005];

inline bool check(int x){
	int cnt=1;
	int tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]+tot<=x) tot+=a[i];
		else{
			tot=a[i];
			cnt++;
		}
	}
	if(cnt>m) return false;
	else return true;
}

int main(){
	cin>>n>>m;
	int l=0,r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=max(l,a[i]);
		r+=a[i];
	}
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
} 
