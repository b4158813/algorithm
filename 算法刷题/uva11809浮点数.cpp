#include<stdio.h>
#include<cmath>
#include<string.h>
#include<iostream>
//#define err 1e-4
using namespace std;
long long M[20][35];
double E[20][35];

int main(){
	char s[100];
	while(cin>>s,(strcmp(s,"0e0"))){
		double A;
		long long B;
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='e') s[i]=' ';
		}
//		for(int i=0;i<strlen(s);i++){
//			cout<<s[i];
//		}
		
		sscanf(s,"%lf%lld",&A,&B);
//		cout<<A<<' '<<B<<endl;
		
		int i=0,j=0;
		double m;
		for(i=0;i<=9;i++){
			for(j=1;j<=30;j++){
				m=log10(1-pow(2,-1-i))+log10(2)*(pow(2,j)-1);
				M[i][j]=m;
				E[i][j]=pow(10,m-M[i][j]);
//				cout<<E[i][j]<<endl;
			}
		}
		i=j=0;
		for(i=0;i<=9;i++){
			for(j=1;j<=30;j++){
				if(B==M[i][j]&&fabs(A-E[i][j])<1e-5)
				{cout<<i<<' '<<j<<endl;}
			}
		}
	}
	return 0;
}
