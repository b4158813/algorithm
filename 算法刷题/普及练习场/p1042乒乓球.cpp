#include<bits/stdc++.h>
using namespace std;

char c[70000];

int main(){
	int i=0;
	while(1){
		cin>>c[i];
		if(c[i]=='E') break;
		i++;
	}
	int w=0,l=0;
	for(int i=0;i<strlen(c);i++){
		if(c[i]=='W') w++;
		if(c[i]=='L') l++;
		if((abs(w-l)>=2&&((w+l)>=20||w==11||l==11))||i==strlen(c)-1) {
			cout<<w<<":"<<l<<endl;
			w=0;l=0;
		}
	}
	cout<<endl;
	w=0;l=0;
	for(int i=0;i<strlen(c);i++){
		if(c[i]=='W') w++;
		if(c[i]=='L') l++;
		if((abs(w-l)>=2&&((w+l)>=40||w==21||l==21))||i==strlen(c)-1) {
			cout<<w<<":"<<l<<endl;
			w=0;l=0;
		}
	}
	return 0;
}
