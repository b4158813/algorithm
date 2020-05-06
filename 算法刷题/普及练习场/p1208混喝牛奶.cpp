#include<bits/stdc++.h>
using namespace std;

struct nn{
	int num,dj;
}nai[5005];

bool cmp(nn n1,nn n2){
	return n1.dj<n2.dj;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>nai[i].dj>>nai[i].num;
	}
	sort(nai+1,nai+m+1,cmp);
//	for(int i=1;i<=m;i++){
//		cout<<nai[i].dj<<" "<<nai[i].num<<endl;
//	}
	int nsum=0,sum=0;
	for(int i=1;i<=m;i++){
		if(nsum<n){
			if(nai[i].num<=n-nsum){
				sum+=nai[i].num*nai[i].dj;
				nsum+=nai[i].num;
			}
			else if(nai[i].num>n-nsum){
				sum+=(n-nsum)*nai[i].dj;
				nsum=n;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
