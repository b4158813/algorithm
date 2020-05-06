#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int inv[3000005];
int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	inv[0]=0,inv[1]=1;
	printf("1\n");
	for(int i=2;i<=n;i++){
		inv[i]=(ll)(p-p/i)*inv[p%i]%p;
		printf("%d\n",inv[i]);
	}
	return 0;
}
