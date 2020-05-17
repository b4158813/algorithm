#include<bits/stdc++.h>
using namespace std;

double a[3][3],ans=1;
char b[3]={'W','W','W'},biao[3]={'W','T','L'};

int main(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	for(int i=0;i<3;i++){
		double tp=a[i][0];
		for(int j=1;j<3;j++){
			if(a[i][j]>tp){
				tp=a[i][j],
				b[i]=biao[j];
			}
		}
		ans*=tp;
	}
	ans=(ans*0.65-1)*2;
	printf("%c %c %c %.2lf",b[0],b[1],b[2],ans);
	return 0;
}