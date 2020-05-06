#include<bits/stdc++.h>
using namespace std;
bool f[100000000];
int prime[5800000];
int cnt;
int main(){
	int n;
	scanf("%d",&n);
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++){
		if(!f[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			f[i*prime[j]]=1;
			if(!(i%prime[j])) break;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
