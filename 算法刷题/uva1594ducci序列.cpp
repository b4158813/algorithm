#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int num[maxn],num2[maxn];//开了两个数组用来存储 

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
		for(int j=0;j<1000;j++){//最多1000步就输出答案 
			if((j+1)%2!=0){//如果是奇数次的变换 
				for(int i=0;i<n-1;i++){//这里把一个数组的值计算好赋值到另一个里面 
					num2[i]=abs(num[i]-num[i+1]);
				}
					num2[n-1]=abs(num[n-1]-num[0]);//最后一个
				}
			else{
				for(int i=0;i<n-1;i++){//同上，交替变换 
					num[i]=abs(num2[i]-num2[i+1]);
				}
				num[n-1]=abs(num2[n-1]-num2[0]);
			}
		}
			
		for(int i=0;i<n;i++){
			sum+=num[i];//1000次就好了，所以不管取哪一个数组输出都行 
		}
		if(!sum) cout<<"ZERO"<<endl;//输出答案 
		else cout<<"LOOP"<<endl;
	}
	return 0;
}
