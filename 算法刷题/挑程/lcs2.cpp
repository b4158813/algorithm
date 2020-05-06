#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],f[100005];
int fun[100005],len;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fun[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(f[len]<fun[b[i]]){
			f[++len] = fun[b[i]];
		}else{
			int pos = lower_bound(f+1,f+1+len,fun[b[i]])-f;
			f[pos] = fun[b[i]];
		}
	}
	cout<<len<<endl;
	return 0;
}
