#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
	int p1,p2,p3;
	cin>>p1>>p2>>p3>>s;
	int i=0;
	while(s[i]){
		if(s[i]=='-'){
			if(!s[i-1]||!s[i+1]||s[i+1]=='-'||s[i-1]=='-'){
				cout<<s[i];i++;continue;
			}
			else if((s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='0'&&s[i+1]<='9')||(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='a'&&s[i+1]<='z'))
			{
				cout<<s[i];i++;continue;
			}
			else if(s[i-1]==s[i+1]-1){
				i++;continue;
			}
			else if(s[i-1]>=s[i+1]){
				cout<<s[i];i++;continue;
			}
			else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'){
				if(p3==1){
					for(int j=0;j<(s[i+1]-s[i-1])-1;j++){
						for(int k=0;k<p2;k++){
							if(p1==1)
								printf("%c",s[i-1]+j+1);
							if(p1==2)
								printf("%c",s[i-1]+j+1-('a'-'A'));
							if(p1==3)
								cout<<"*";
						}
					}
					
				} else if(p3==2){
					for(int j=(s[i+1]-s[i-1])-1;j>0;j--){
						for(int k=0;k<p2;k++){
							if(p1==1)
								printf("%c",s[i-1]+j);
							if(p1==2)
								printf("%c",s[i-1]+j-('a'-'A'));
							if(p1==3)
								cout<<"*";
						}
					}
				}
				i++;continue;
			} else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'){
				if(p3==1){
					for(int j=0;j<(s[i+1]-s[i-1])-1;j++){
						for(int k=0;k<p2;k++){
							if(p1==3)
								cout<<"*";
							else printf("%c",s[i-1]+j+1);
						}
					}
				} else if(p3==2){
					for(int j=(s[i+1]-s[i-1])-1;j>0;j--){
						for(int k=0;k<p2;k++){
							if(p1==3)
								cout<<"*";
							else printf("%c",s[i-1]+j);
						}
					}
				}
				i++;continue;
			}
		}
		else {
			cout<<s[i];i++;continue;
		}
	}
	return 0;
}
