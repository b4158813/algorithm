#include<bits/stdc++.h>
using namespace std;
int n,p;
//int cnt,f[3000005],eu[3000005],prime[1000005];
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
inline int qpow(int x,int y){
	int base=x,ans=1;
	while(y>0){
		if(y&1){
			ans=(long long )ans*base%p;
		}
		base=(long long )base*base%p;
		y>>=1;
	}
	return ans;
}
int main(){
	n=read(),p=read();
	for(register int i=1;i<=n;i++){
		printf("%d\n",(qpow(i,p-2))%p);
	}
	return 0;
	
}
