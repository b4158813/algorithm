#include<bits/stdc++.h>
using namespace std;

int main(){
	string num;
	while(cin>>num&&(int)(num[0]-'0')){
		int sum = 0;
		//cout<<num.length()<<endl;
		for (int i=num.length()-1;i>=0;i--){
			if(num[i]<='F'&&num[i]>='A'){
				sum += (num[i]-'A'+10)*pow(16,num.length()-i-1);
			}
			else {
				sum += (num[i]-'0')*pow(16,num.length()-i-1);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
