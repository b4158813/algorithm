#include<bits/stdc++.h>
using namespace std;

string s1[205],s2[205],s1z[105],s1x[105],s2z[105],s2x[105];
int num[1005];
int nn1,nn2;

void gplus(){
	int lenx=max(s1x,s2x);
	int c=0,x=0;
	for(int i=0;i<lenx;i++){
		int sum=s1x[i]+b[i]+x;
		c=sum%10;
		x=sum/10;
		num[i]=c;
	}
	c=0,x=0;
	for(int i=0;i<lenz;i++){
		int sum=a[i]+b[i]+x;
		c=sum%10;
		x=sum/10;
		num[i]=c;
	}
	
}

int main(){
	cin>>s1>>s2;
	memset(num,0,sizeof(num));
	memset(s1x,0,sizeof(s1x));
	memset(s1z,0,sizeof(s1z));
	memset(s2z,0,sizeof(s2z));
	memset(s2x,0,sizeof(s2x));
	for(int i=0;i<s1.length();i++){
		s1z[i]=s1[i];
		if(s1[i]=='.'){
			nn1=i;break;
		}
	}
	for(int i=0;i<s2.length();i++){
		s2z[i]=s2[i];
		if(s2[i]=='.'){
			nn2=i;break;
		}
	}
	for(int i=nn1;i<s1.length();i++){
		s1x[i]=s1[i];
	}
	for(int i=nn2;i<s2.length();i++){
		s2x[i]=s2[i];
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
