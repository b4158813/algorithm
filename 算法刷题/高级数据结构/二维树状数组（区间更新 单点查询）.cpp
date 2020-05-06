#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,mm[1005][1005];
inline int lowbit(int x){return x&-x;}
inline void update(int x,int y,int k){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=n;j+=lowbit(j)){
			mm[i][j]+=k;
		}
	}
}
inline int getsum(int x,int y){
	int res=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			res+=mm[i][j];
		}
	}
	return res;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		memset(mm,0,sizeof(mm));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			char c;
			cin>>c;
			if(c=='C'){
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				update(x1,y1,1);
				update(x2+1,y2+1,1);
				update(x1,y2+1,-1);
				update(x2+1,y1,-1); 
			}
			else {
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",getsum(x,y)%2);
			}
		}
		if(t) printf("\n");
	}
	return 0;
}
