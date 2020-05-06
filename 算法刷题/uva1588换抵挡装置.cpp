#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn=105;
char n1[maxn],n2[maxn];

int main(){
	memset(n1,'0',sizeof(n1));
	memset(n2,'0',sizeof(n2));
	while(cin>>n1>>n2){
		int x,y,i,j,lens=strlen(n1),lent=strlen(n2);
		for(i=0;i<lens;i++){
			bool flag=true;
			for(j=0;j<lent&&i+j<lens;j++){
				if(n1[i+j]=='2'&&n2[j]=='2'){
					flag=false;break;
				}
			}
			if(flag) break;
		}
		x=max(lens,lent+i);
		i=j=0;
		for(i=0;i<lent;i++){
			bool flag=true;
			for(j=0;j<lens&&i+j<lent;j++){
				if(n2[i+j]=='2'&&n1[j]=='2'){
					flag=false;break;
				}
			}
			if(flag) break;
		}
		y=max(lent,lens+i);
		cout<<min(x,y)<<endl;
	}
	return 0;
}
