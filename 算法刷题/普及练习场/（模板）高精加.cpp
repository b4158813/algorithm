#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int num[1005];
int a[1005],b[1005];
int nn1,nn2;
 
void gplus(){
	int len=max(nn1,nn2)+1;
	int c=0,x=0;
	for(int i=0;i<len;i++){
		int sum=a[i]+b[i]+x;
		c=sum%10;
		x=sum/10;
		num[i]=c;
	}
	
}

int main(){
	cin>>s1>>s2;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(num,0,sizeof(num));
	nn1=0;
	for(int i=s1.length()-1;i>=0;i--){
		a[nn1++]=s1[i]-'0';
	}
	
	nn2=0;
	for(int j=s2.length()-1;j>=0;j--){
		b[nn2++]=s2[j]-'0';
	}
	gplus();
	int pos;
	for(int i=1005;i>=0;i--){
		if(num[i]!=0){
			pos=i;break;
		}
	}
	for(int i=pos;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
