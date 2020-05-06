#include<bits/stdc++.h>
using namespace std;

char f[10005];
int main(){
	cin>>f;
	int len=strlen(f);
	int sum=0;
	for(int i=0;i<len;i++) sum+=f[i]-'0';
	if((f[len-1]-'0')%2==0) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	if(sum%3==0) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	if(((f[len-1]-'0')+(f[len-2]-'0')*10)%4==0) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	if(((f[len-1]-'0')+(f[len-2]-'0')*10+(f[len-3]-'0')*100)%8==0)
		cout<<"1"<<endl;
	else cout<<"0"<<endl;
	if((f[len-1]-'0')==0||(f[len-1]-'0')==1||(f[len-1]-'0')==4||(f[len-1]-'0')==5||(f[len-1]-'0')==6||(f[len-1]-'0')==9)
		cout<<"1"<<endl;
	else cout<<"0"<<endl;
	return 0;
	
}
