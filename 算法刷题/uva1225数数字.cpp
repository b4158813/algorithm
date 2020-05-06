#include<iostream>
#include<cstring>
#include<iomanip>
#include<string>
#include<string.h>
using namespace std;
#define maxn 10000

char a[maxn];


int main(){
	int n,count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0;
	memset(a,0,sizeof(a));
	while(cin>>n){
		int b[maxn];
		for(int i=0;i<n;i++) b[i]=i+1;
		for(int i=0;i<n;i++){
			if(b[i]<9){
				if(b[i]==0) count0++;
				if(b[i]==1) count1++;
				if(b[i]==2) count2++;
				if(b[i]==3) count3++;
				if(b[i]==4) count4++;
				if(b[i]==5) count5++;
				if(b[i]==6) count6++;
				if(b[i]==7) count7++;
				if(b[i]==8) count8++;
				if(b[i]==9) count9++;
			}
			else{
				int x=b[i],p;
				while(x){
					p=x%10;
					if(p==0) count0++;
					if(p==1) count1++;
					if(p==2) count2++;
					if(p==3) count3++;
					if(p==4) count4++;
					if(p==5) count5++;
					if(p==6) count6++;
					if(p==7) count7++;
					if(p==8) count8++;
					if(p==9) count9++;
					x/=10;
				}
			}
		}
		for(int i=0;i<n;i++) cout<<b[i]<<" ";
		cout<<endl;
		printf("%d %d %d %d %d %d %d %d %d %d",count0,count1,count2,count3,count4,count5,count6,count7,count8,count9);
	
		}
	}
