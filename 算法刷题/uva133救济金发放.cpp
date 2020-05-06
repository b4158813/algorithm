#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
char a[maxn];

int main(){
	int n,k,m;
	while(cin>>n>>k>>m&&(m||n||k)){
		for(int i=1;i<=n;i++){
			a[i]=1;
		}
		a[0]=a[n];
	int p=0,q=n+1,N=n;
		while(n){
			int k1=k,m1=m;
			while(k1--){
				p=(p+1)%N;
				if(p==0)p=N;
				if(a[p]==0){
					k1+=1;continue;
				}
			}
			while(m1--){
				q=(q+(N-1))%N;
				if(q==0)q=N;
				if(a[q]==0){
					m1+=1;continue;
				}
			}
			a[p]=a[q]=0;
			n-=2;
			if(p==q){
				n++;
				printf("%3d",p);
				if(n)cout<<",";
				if(!n)cout<<endl;
			}
			else {
				printf("%3d%3d",p,q);
				if(n)cout<<",";
				if(!n)cout<<endl;
				}
		}
	}
	return 0;
}
