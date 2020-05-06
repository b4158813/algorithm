#include<bits/stdc++.h>
using namespace std;
#define maxn 20
char s[maxn],a1[maxn],a2[maxn];
int main(){
	while(cin>>s){
		for(int i=0;i<6;i++){
			a1[i+1]=s[i];
			a2[i+1]=s[i+6];
		}
		for(int i=1;i<=6;i++){
			if(a1[i]=='*')continue;
			for(int j=1;j<=6;j++){
				if(a2[j]=='*')continue;
				if(a1[i]==a2[j]){
					if(a1[7-i]==a2[7-j]){
						a1[i]=a1[7-i]=a2[j]=a2[7-j]='*';break;
					}
				}
			}
		}
		bool flag=true;
		for(int i=1;i<=6;i++) 
			if(!(a1[i]==a2[i])) flag=false;
			
			if(flag) cout<<"TRUE"<<endl;
			else cout<<"FALSE"<<endl;
	}
	return 0;
}
