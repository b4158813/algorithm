#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
char ch[maxn][100];
int s[maxn],step[maxn];


int main(){
	int sum=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]>>ch[i];
	}
	for(int i=0;i<m;i++){
		cin>>s[i]>>step[i];
		if((a[sum]+s[i])%2==0){
			sum-=step[i];
			while(sum<0) sum+=n;
			while(sum>=n) sum-=n;
		//	cout<<sum<<endl;
		}
		else if((a[sum]+s[i])%2==1){
			sum+=step[i];
			while(sum<0) sum+=n;
			while(sum>=n) sum-=n;
		//	cout<<sum<<endl;
		}
	}
	cout<<ch[sum]<<endl;
	return 0;
}
