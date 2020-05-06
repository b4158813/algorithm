#include <iostream>
#include <iomanip>
#include <string.h>
#define maxn 105
using namespace std;
int lessthan(const char *s,int p,int q);

int lessthan(const char*s,int p,int q){
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[(i+p)%n]!=s[(i+q)%n]) 
			return s[(i+p)%n]<s[(i+q)%n];
	}
	return 0;//注意这里return在for循环外面！ 
}

int main(){
	char s[maxn];
	while((scanf("%s",s))==1){
		int len = strlen(s);
		int ans=0;
		for(int i=1;i<len;i++){
			if(lessthan(s,i,ans)) ans=i;//如果s[i]比s[ans]小，则把ans置为i，继续比较 
		}
		for(int i=0;i<len;i++){
			cout<<s[(i+ans)%len];
		}
		cout<<endl;
	}
	
	return 0;

}
