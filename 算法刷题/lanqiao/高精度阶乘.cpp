#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000;
int f[maxn];

int main(){
	int n;
	while(cin>>n&&n){
		memset(f,0,sizeof(f));
		f[0]=1;
		for(int i=2;i<=n;i++){
			int c=0;
			for(int j=0;j<maxn;j++){
				int s = i*f[j]+c;
				f[j] = s%10;
				c = s/10;
			}
		}
		int i=maxn-1;
		for(i;;i--){
			if(f[i]) break;
		}
		for(int j = i;j>=0;j--){
			cout<<f[j];
		}
		cout<<endl;
	}
	return 0;
}
