#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1<<30;

ll f[100005],a[100005];
ll n;
ll len;

//int bound(int x){
//	int l=1,r=len;
//	while(l<r){
//		int mid = (l+r)>>1;
//		if(f[mid]>x){
//			r=mid;
//		}else l=mid+1;
//	}
//	return l;
//}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(f[len]<a[i]){
			f[++len] = a[i];
		}else{
			int pos = lower_bound(f+1,f+len+1,a[i])-f;
			f[pos] = a[i];
		}
		//cout<<len<<" ";
	}
	cout<<len<<endl;
	return 0;
}
