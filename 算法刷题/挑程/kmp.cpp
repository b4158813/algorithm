#include<bits/stdc++.h>
using namespace std;
int kmp[1000005];
char a[1000005],b[1000005];
int main(){
	cin>>a+1;
	cin>>b+1;
	int lena=strlen(a+1),lenb=strlen(b+1);
//	cout<<lena<<endl<<lenb<<endl;
	int j=0;
	for(int i=2;i<=lenb;i++){
		while(j&&b[j+1]!=b[i]) j=kmp[j];
		if(b[j+1]==b[i]) j++;
		kmp[i]=j; 
	}
	j=0;
	for(int i=1;i<=lena;i++){
		while(j&&b[j+1]!=a[i]) j=kmp[j];
		if(b[j+1]==a[i]) j++;
		if(j==lenb){
			cout<<i-lenb+1<<endl;
			j=kmp[j];
		}
	}
	for(int i=1;i<=lenb;i++){
		cout<<kmp[i]<<" ";
	}
	return 0;
}
