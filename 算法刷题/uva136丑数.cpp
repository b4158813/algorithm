#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll num[1505]={0,1};//�����洢�� 
	int n1=1,n2=1,n3=1;//һ�����������±� 
	ll x;
	for(ll i=2;i<=1500;i++){//�ҵ�1500����ͣ
		//��2��3��5�������ҳ���С����һ��������������棬Ȼ���Ӧ�±�++ 
		x = min(min(2*num[n1],3*num[n2]),5*num[n3]);
		num[i]=x;//������������� 
		//��Ӧ�±�++��ͬʱȥ�� 
		if(x==2*num[n1]) n1++;
		if(x==3*num[n2]) n2++;
		if(x==5*num[n3]) n3++;
	}
	cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
}
