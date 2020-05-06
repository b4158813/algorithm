#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//map<int,int > m;

bool isprime(int  x){
	if(x==1) return false;
	if(x==2) return true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

int  ishuiwen(int x){
	int k=x,sum=0;
		while(x){
			sum = sum*10+x%10;
			//cout<<z<<endl;
			x/=10;
		}
		if(k==sum) return 1;
		else return 0;
}

int main(){
	int a,b;
	cin>>a>>b;
	//if(a%2!=0)
		for(int i=a;i<=b;i++){
			if(i==9989900) break;
			if(ishuiwen(i)&&isprime(i)) cout<<i<<endl;
		}
//	else
//		for(ll i=a+1;i<=b;i=i+2){
//			if(i==9989900) break;
//			if(isprime(i)&&ishuiwen(i)) cout<<i<<endl;
//		}
	
	return 0;
}
