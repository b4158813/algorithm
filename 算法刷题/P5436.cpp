#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int _,n;
int main(){
	for(scanf("%d",&_);_;_--){
		scanf("%d",&n);
		if(n==1) printf("1\n");
		else printf("%lld\n",(ll)n*(n-1));
	}
	return 0;
}