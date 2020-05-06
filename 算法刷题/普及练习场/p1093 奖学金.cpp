#include<bits/stdc++.h>
using namespace std;

struct stu{
	int ch,ma,en,num;
}st[305];

bool cmp(stu s1, stu s2){
	if(s1.ch+s1.ma+s1.en==s2.ch+s2.ma+s2.en) {
		if(s1.ch==s2.ch) return s1.num<s2.num;
		return s1.ch>s2.ch;
	}
	return s1.ch+s1.ma+s1.en>s2.ch+s2.ma+s2.en;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i].ch>>st[i].ma>>st[i].en;
		st[i].num=i;
	}
	sort(st+1,st+n+1,cmp);
	for(int i=1;i<=5;i++){
		cout<<st[i].num<<" "<<st[i].ch+st[i].ma+st[i].en<<endl;
	}
	return 0;
}
