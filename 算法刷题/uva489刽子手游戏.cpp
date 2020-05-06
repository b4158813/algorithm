#include<bits/stdc++.h>
using namespace std;

char a[100],b[100]; 
int win,lose,w=7,leftt;//´íw´Î¾Ílose

void guess(char ch){
	int bad=1;
	for(int i=0;i<strlen(a);i++){
		if(a[i]==ch){
			leftt--;
			a[i]=' ';
			bad=0;
		}
	}
	if(bad) w--;
	if(!w) lose=1;
	if(!leftt) win=1;
}
int main(){
	int T;
	while(cin>>T&&(T!=-1)){
		cin>>a;
		cin>>b;
		leftt=strlen(a);
		cout<<"Round "<<T<<endl;
		for(int i=0;i<strlen(b);i++){
			guess(b[i]);
			if(win||lose) break; 
		}
		if(win)cout<<"You win."<<endl;
		else if(lose)cout<<"You lose."<<endl;
		else cout<<"You chickened out."<<endl;
	}
	return 0;
}
