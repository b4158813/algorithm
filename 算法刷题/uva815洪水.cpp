#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int s[maxn],vol;
long long sum;
bool guanshui(int mid){
	sum=0;
	for(int x=1;x<mid;x++){
		sum+=(s[mid]-s[x])*10*10;
	}
	if(vol>sum) return 1;
	else return 0;
}

int main(){
	int m,n,count=0;
	double h,p;
	while(cin>>n>>m&&(n||m)){
//		if(count) cout<<endl;
		memset(s,0,sizeof(s));
		int tot=n*m,res;
		for(int i=1;i<=tot;i++){
			cin>>s[i];
		}
		cin>>vol;
		sort(s+1,s+tot+1);
//		for(int i=1;i<=tot;i++) cout<<s[i]<<endl;
		int l=0,r=tot,mid,ansp;
		while(l<=r){
			mid=(l+r)>>1;
			if(guanshui(mid)){
				ansp=mid;
				l=mid+1;
				res=sum;
			}
			else{
				r=mid-1;
			}
		}
//		cout<<mid<<endl;
		h=1.0*s[ansp]+1.0*(vol-res)/(10*10*ansp);
		p=100.0*ansp/tot;
		cout<<"Region "<<++count<<endl;
		printf("Water level is %.2lf meters.\n",h);
		printf("%.2lf percent of the region is under water.\n",p);
		cout<<endl;
	}
	return 0;
}
