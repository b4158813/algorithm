#include<bits/stdc++.h>
using namespace std;

int n,cnt,f[10005];
int gethw(int x);

inline bool ishw(int x){
	return gethw(x)==x;
}

inline int gethw(int x){
	int temp=x,giao=0,ans=0;
	while(temp){
		giao=temp%10;
		ans=ans*10+giao;
		temp/=10;
	}
	return ans;
}

int main(){
	while(~scanf("%d",&n)){
		cnt=0;
		f[++cnt]=n;
		while(1){
			n+=gethw(n);
			f[++cnt]=n;
			if(ishw(n)) break;
		}
		printf("%d\n",cnt-1);
		for(int i=1;i<=cnt;i++){
			if(i!=cnt) printf("%d--->",f[i]);
			else printf("%d\n",f[i]);
		}
	}
	return 0;
}
