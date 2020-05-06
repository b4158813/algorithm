#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000005;
int s[maxn],p[maxn];
long long ans;

void msort(int l, int r){
	int mid = (l+r)>>1;
	if(l==r) return;
	msort(l,mid);msort(mid+1,r);
	int i = l, j=mid+1,t=l;
	while(i<=mid&&j<=r){
		if(s[i]>s[j]){
			ans += mid-i+1;
			p[t++] = s[j++];
		}
		else p[t++] = s[i++];
	}
	while(i<=mid) p[t++]=s[i++];
	while(j<=r) p[t++]=s[j++];
	for(int k=l;k<=r;k++) s[k]=p[k];
	return;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	msort(1,n);
	cout<<ans<<endl;
	return 0;
}
