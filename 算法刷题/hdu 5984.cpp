#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		double x,y;
		cin>>x>>y;
		if(x<=y) cout<<"0.000000"<<endl;
		else printf("%.6lf\n",log(x/y)+1.0);
	}
	return 0;
}
