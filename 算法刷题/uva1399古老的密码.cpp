#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
char a[maxn],b[maxn];
int numa[300],numb[300];

int main(){
	while(cin>>a>>b){
	memset(numa,0,sizeof(numa));
	memset(numb,0,sizeof(numb));
	for(int i=0;i<strlen(a);i++)
		numa[a[i]-'A']++;
	for(int i=0;i<strlen(b);i++)
		numb[b[i]-'A']++;
	sort(numa,numa+26);
	sort(numb,numb+26);
	bool bo=true;
	for(int i=0;i<26;i++){
		if(numa[i]!=numb[i]){
			cout<<"NO"<<endl;bo=false;break;
			}
		}
	if(bo) cout<<"YES"<<endl;
	}
	return 0;
}
