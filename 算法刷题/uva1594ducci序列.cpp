#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int num[maxn],num2[maxn];//�����������������洢 

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		for(int j=0;j<1000;j++){//���1000��������� 
			if((j+1)%2!=0){//����������εı任 
				for(int i=0;i<n-1;i++){//�����һ�������ֵ����ø�ֵ����һ������ 
					num2[i]=abs(num[i]-num[i+1]);
				}
					num2[n-1]=abs(num[n-1]-num[0]);//���һ��
				}
			else{
				for(int i=0;i<n-1;i++){//ͬ�ϣ�����任 
					num[i]=abs(num2[i]-num2[i+1]);
				}
				num[n-1]=abs(num2[n-1]-num2[0]);
			}
		}
			
		for(int i=0;i<n;i++){
			sum+=num[i];//1000�ξͺ��ˣ����Բ���ȡ��һ������������� 
		}
		if(!sum) cout<<"ZERO"<<endl;//����� 
		else cout<<"LOOP"<<endl;
	}
	return 0;
}
