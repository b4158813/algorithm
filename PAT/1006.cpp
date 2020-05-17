#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	string id,t1,t2;
}a[100005];
bool cmp1(node x1,node x2){
	string s1=x1.t1.substr(0,2),s2=x2.t1.substr(0,2);
	string y1=x1.t1.substr(3,2),y2=x2.t1.substr(3,2);
	string z1=x1.t1.substr(6,2),z2=x2.t1.substr(6,2);
	if(s1==s2&&y1==y2) return z1<z2;
	if(s1==s2) return y1<y2;
	return s1<s2;
}

bool cmp2(node x1,node x2){
	string s1=x1.t2.substr(0,2),s2=x2.t2.substr(0,2);
	string y1=x1.t2.substr(3,2),y2=x2.t2.substr(3,2);
	string z1=x1.t2.substr(6,2),z2=x2.t2.substr(6,2);
	if(s1==s2&&y1==y2) return z1>z2;
	if(s1==s2) return y1>y2;
	return s1>s2;
}


int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].id>>a[i].t1>>a[i].t2;
	}
	sort(a+1,a+1+n,cmp1);
	cout<<a[1].id<<" ";
	sort(a+1,a+1+n,cmp2);
	cout<<a[1].id;
	return 0;
}