#include<bits/stdc++.h>
using namespace std;

int a[105],c=0,b[105];
bool cnt[1005];

int main(){
	int n;
	memset(a,-1,sizeof(a));
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1;
	while(1){
		if(a[i]==-1) break;
		if(cnt[a[i]]) c++;
		cnt[a[i]]=1;
		i++;
	}
	cout<<n-c<<endl;
	memset(cnt,0,sizeof(cnt));
	i=1; int k=1;
	while(1){
		if(a[i]==-1) break;
		if(cnt[a[i]]) {
			i++;continue;
		}
		cnt[a[i]]=1;
		b[k++]=a[i++];
	}
	sort(b,b+k);
	for(int i=1;i<k;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
