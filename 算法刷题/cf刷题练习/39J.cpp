#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
string s1,s2;
int ans,cnt,Ans[1000005];
char c;
int main() {
    cin>>s1>>s2;
    c='*';
    int len1=s1.size(),len2=len1-1;
	for(int i=0,j=0;i<len1;){
		if(s2[j]!=s1[i]){
			if(c=='*'){
				c=s1[i];
				ans=i+1;
				i++;
				continue;
			}
			else{
				if(s1[i]!=c){
					printf("0\n");
					return 0;
				}
				ans=i+1;
				i++;continue;
			}
		}
		
		i++,j++;
	}
	Ans[++cnt]=ans;
	for(int i=ans-2;i>=0;i--){
		if(s1[i]!=s1[i+1]){
			break;
		}
		Ans[++cnt]=i+1;
	}
	printf("%d\n",cnt);
	for(int i=cnt;i>=1;i--){
		printf("%d ",Ans[i]);
	}
    return 0;
}

