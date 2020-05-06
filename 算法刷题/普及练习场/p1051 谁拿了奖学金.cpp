#include<bits/stdc++.h>
using namespace std;

struct stu{
	string name;
	int qm,bj,lw,num,jxj;
	char gb,xb;
}st[105];

bool cmp(stu s1, stu s2){
	if(s1.jxj==s2.jxj) {
		return s1.num<s2.num;
	}
	return s1.jxj>s2.jxj;
}

int main(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i].name>>st[i].qm>>st[i].bj>>st[i].gb>>st[i].xb>>st[i].lw;
		st[i].num=i;
		if(st[i].qm>80&&st[i].lw>=1) st[i].jxj+=8000;
		if(st[i].qm>85&&st[i].bj>80) st[i].jxj+=4000;
		if(st[i].qm>90) st[i].jxj+=2000;
		if(st[i].qm>85&&st[i].xb=='Y') st[i].jxj+=1000;
		if(st[i].bj>80&&st[i].gb=='Y') st[i].jxj+=850;
		sum+=st[i].jxj;
	}
	sort(st+1,st+n+1,cmp);
	cout<<st[1].name;
	printf("\n%d\n%d\n",st[1].jxj,sum);
	return 0;
}
