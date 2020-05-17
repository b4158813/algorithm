#include<bits/stdc++.h>
using namespace std;
struct node
{
	int id,grade;
	string name;
}a[500005];
int n,m;
bool cmp1(node x1,node x2){
	return x1.id<x2.id;
}
bool cmp2(node x1,node x2){
	if(x1.name==x2.name) return x1.id<x2.id;
	return x1.name<x2.name;
}
bool cmp3(node x1,node x2){
	if(x1.grade==x2.grade) return x1.id<x2.id;
	return x1.grade<x2.grade;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i].id>>a[i].name>>a[i].grade;
	}
	if(m==1) sort(a+1,a+1+n,cmp1);
	else if(m==2) sort(a+1,a+1+n,cmp2);
	else if(m==3) sort(a+1,a+1+n,cmp3);
	for(int i=1;i<=n;i++){
		printf("%06d %s %d\n",a[i].id,a[i].name.c_str(),a[i].grade);
	}
	return 0;
}