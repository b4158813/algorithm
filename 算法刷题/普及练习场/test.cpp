#include<bits/stdc++.h>
using namespace std;

double a,b,c,d;



int main(){
	cin>>a>>b>>c>>d;
	double i;
	for(i=-100;i<=100;i+=0.01){
		if(fabs(a*i*i*i+b*i*i+c*i+d)<1e-6){
			printf("%.2lf ",i);
		}
	}
	return 0;
}
