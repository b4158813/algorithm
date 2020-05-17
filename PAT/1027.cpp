#include<bits/stdc++.h>
using namespace std;
int a,b,c;
map<int,char> ma;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	ma[10]='A',ma[11]='B',ma[12]='C';
	printf("#");
	vector<int> ha;
	while(a){
		ha.push_back(a%13);
		a/=13;
	}
	if(ha.size()==0) printf("00");
	if(ha.size()==1) printf("0");
	for(int i=ha.size()-1;i>=0;i--){
		if(ha[i]>=10) printf("%c",ma[ha[i]]);
		else printf("%d",ha[i]);
	}
	ha.clear();
	while(b){
		ha.push_back(b%13);
		b/=13;
	}
	if(ha.size()==0) printf("00");
	if(ha.size()==1) printf("0");
	for(int i=ha.size()-1;i>=0;i--){
		if(ha[i]>=10) printf("%c",ma[ha[i]]);
		else printf("%d",ha[i]);
	}
	ha.clear();
	while(c){
		ha.push_back(c%13);
		c/=13;
	}
	if(ha.size()==0) printf("00");
	if(ha.size()==1) printf("0");
	for(int i=ha.size()-1;i>=0;i--){
		if(ha[i]>=10) printf("%c",ma[ha[i]]);
		else printf("%d",ha[i]);
	}
	return 0;
}