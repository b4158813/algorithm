#include<bits/stdc++.h>
using namespace std;
string s,t[205];
int kmp[205],sum[200005];
int main() {
	int cnt=1;
    while(cin>>t[cnt]){
    	if(t[cnt]=="."){
    		cnt--;
    		break;
		}
		t[cnt]="0"+t[cnt];
//		cout<<t[cnt]<<endl;
    	cnt++;
	}
	string temp;
	s+="0";
	while(cin>>temp){
		s+=temp;
	}
	int len=s.size();
//	cout<<s<<endl;
	for(int k=1;k<=cnt;k++){
		memset(kmp,0,sizeof(kmp));
		int j=0;
		for(int i=2;i<=t[k].size();i++){
			while(j&&t[k][j+1]!=t[k][i]) j=kmp[j];
			if(t[k][j+1]==t[k][i]) j++;
			kmp[i]=j;
		}
		j=0;
		for(int i=1;i<=len;i++){
			while(j&&t[k][j+1]!=s[i]) j=kmp[j];
			if(t[k][j+1]==s[i]) j++;
			if(j==t[k].size()-1){
				sum[i-t[k].size()+2]++;
				sum[i+1]--;
//				printf("sumz:%d sumy:%d\n",i-t[k].size()+2,i+1);
				j=kmp[j];
			}
		}
	}
	for(int i=1;i<=len;i++){
		sum[i]+=sum[i-1];
		if(sum[i]<=0){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<len<<endl;
    return 0;
}
