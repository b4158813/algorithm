#include<bits/stdc++.h>
using namespace std;

struct pe{
	int num,t;
}p[1005];

bool cmp(pe m1,pe m2){
	return m1.t<m2.t;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].t;
		p[i].num=i;
	}
	sort(p+1,p+n+1,cmp);
	long long  sumt=0,ssum=0;
	for(int i=1;i<=n;i++){
		cout<<p[i].num<<" ";
		sumt+=p[i].t;
		ssum+=sumt;
	}
	ssum-=sumt;
	printf("\n%.2lf\n",(double)ssum/n);;
	return 0;
} 
