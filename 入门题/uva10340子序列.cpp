#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn=1005;

char s[maxn],t[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>s;
		cin>>t;
		int c=0;
		for(int i=0;i<strlen(s);i++){
			int k=s[i];
			for(int j=c;j<strlen(t);j++){
				if(t[j]==k){
					if(i==strlen(s)-1)cout<<"Y";
					c=j;
					break;				
				}
				if(j==strlen(t)-1){
				cout<<"N";i=strlen(s)-1;break;}
			}
				
		}
	}
	return 0;
}
