#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
#include<tr1/unordered_map>
using namespace std;
using namespace tr1;
typedef long long ll;

int px[2005],py[2005];
int ans=0;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&px[i],&py[i]);
	}
	for(int i=0;i<n;i++){
		map <ll ,ll > m;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			ll dx=px[i]-px[j];
			ll dy=py[i]-py[j];
			ll d=dx*dx+dy*dy;
			m[d]++;
		}
		map <ll, ll>::iterator it=m.begin();
		while(it!=m.end()){
		//	cout<<it->second<<endl;
			ll k=it->second;
			ans+=k*(k-1)*(k-2)/6;
			it++;
		}
	}
	printf("%lld\n",ans);
	return 0;
	
}
