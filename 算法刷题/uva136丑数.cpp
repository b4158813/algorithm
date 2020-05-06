#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll num[1505]={0,1};//用来存储答案 
	int n1=1,n2=1,n3=1;//一个数组三个下标 
	ll x;
	for(ll i=2;i<=1500;i++){//找到1500个就停
		//从2倍3倍5倍里面找出最小的那一个，填到答案数组里面，然后对应下标++ 
		x = min(min(2*num[n1],3*num[n2]),5*num[n3]);
		num[i]=x;//传入答案数组里面 
		//对应下标++，同时去重 
		if(x==2*num[n1]) n1++;
		if(x==3*num[n2]) n2++;
		if(x==5*num[n3]) n3++;
	}
	cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
}
