#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
string s1,s2;
char num[17]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
inline int cal(string x,string y){
	int ans=0;
	for(int i=0;i<x.size();i++){
		ans=max(ans,x[i]-'0');
	}
	for(int j=0;j<y.size();j++){
		ans=max(ans,y[j]-'0');
	}
	return ans;
}
char ans[100005];
int Ans,cnt;
int main() {
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size();
	int len=max(len1,len2);
    int jin=cal(s1,s2);
    if(len1<len2){
    	for(int i=1;i<=len2-len1;i++){
    		s1="0"+s1;
		}
	}else{
		for(int i=1;i<=len1-len2;i++){
			s2="0"+s2;
		}
	}
    for(int i=jin;i<=16;i++){
    	cnt=0;
    	int com=0;
    	for(int j=len-1;j>=0;j--){
    		int temp=s1[j]-'0'+s2[j]-'0'+com;
    		if(temp>i) com=1;
    		else com=0;
    		temp%=i;
			ans[cnt++]=num[temp];
		}
		if(com) ans[cnt++]='1';
		int Len=strlen(ans);
		Ans=max(Ans,Len);
	}
	printf("%d\n",Ans);
    return 0;
}

