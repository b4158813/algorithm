#include<stdio.h>
#include<iostream>
#include<cstring> 
#define maxn 100
using namespace std;

double mass[maxn];

 
int main() { 
	memset(mass,0,sizeof(mass));
	mass['C']=12.01;
	mass['H']=1.008;
	mass['O']=16.00;
	mass['N']=14.01;
	char s[maxn];
	while(cin>>s){
		double sum=0.0;
		int len = strlen(s);
		for(int i=0;i<len;i++){
			if(s[i+1]<'0'||s[i+1]>'9') sum+=mass[s[i]];
			else{
				int size=0,now=i+1;
				while(s[now]<='9'&&s[now]>='0') 
					size=10*size+s[now++]-'0';
				sum+=mass[s[i]]*size;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
 }
