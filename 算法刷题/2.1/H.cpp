#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
char b[1005][1005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		double len = s.length();
		double tlen = sqrt(len)==int(sqrt(len))?int(sqrt(len)):int(sqrt(len))+1;
		int cnt=0;
		for(int i=0;i<tlen;i++){
			for(int j=0;j<tlen;j++){
				++cnt;
				if(cnt>len) a[i][j]='*';
				else a[i][j] = s[i*tlen+j];
			}
		}
		for(int i=0;i<tlen;i++){
			for(int j=0;j<tlen;j++){
				b[i][j] = a[int(tlen)-j-1][i];
				if(b[i][j]!='*'){
					cout<<b[i][j];
				}
			}
		}
		cout<<endl;
	}
}
