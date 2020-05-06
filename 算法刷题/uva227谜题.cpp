#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstring>
using namespace std;
#define maxn 1000
int main(){
	int m,k;
	char a[10][10];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%c",&a[i][j]);
			
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++){
			printf("%c",a[i][j]);
			if(j==4) cout<<endl;
		}
	cin>>m>>k;//mĞĞkÁĞµÄ×Ö·ûÖÃ¿Õ
	a[m][k]=0;
	char s[maxn];
	int i=0;
	while((scanf("%c",&s[i++]))==1&&s[i-1]!='0');
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='A'){
			a[m][k]=a[m-1][k];
			m=m-1;
			a[m][k]=0;
		}
		if(s[i]=='B'){
			a[m][k]=a[m+1][k];
			m=m+1;
			a[m][k]=0;
		}
		if(s[i]=='L'){
			a[m][k]=a[m][k-1];
			k=k-1;
			a[m][k]=0;
		}
		if(s[i]=='R'){
			a[m][k]=a[m][k+1];
			k=k+1;
			a[m][k]=0;
		}
	}
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++){
			printf("%c",a[i][j]);
			if(j==4) cout<<endl;
		}
}
