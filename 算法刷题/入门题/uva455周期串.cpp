#include<cstring>
#include<iostream>
#include<string.h>
using namespace std;
#define maxn 85

char s[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(s,0,sizeof(s));
		scanf("%s",s);
		int len=strlen(s);
		for (int i=1;i<=len;i++){
			if(len%i==0){
				int j;
				for(j=i;j<=len;j++){
					if(s[j]!=s[j%i]) break;}
				if(j==len&&j!=1) {cout<<i<<endl;break;}
			}
		}
	}if(t) cout<<endl;
}
