#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int x[3],y[3];
inline bool isper(int x[3],int y[3]){
	int x1=x[0],x2=x[1],x3=x[2];
	int y1=y[0],y2=y[1],y3=y[2];
	if(((x1-x2)==0&&(y1-y2)==0)||((x1-x3)==0&&(y1-y3)==0)||((x3-x2)==0&&(y3-y2)==0)) return false;
	if((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2)==0) return true;
	if((x1-x3)*(x2-x3)+(y1-y3)*(y2-y3)==0) return true;
	if((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1)==0) return true;
	return false;
}
int main() {
    scanf("%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
	if(isper(x,y)){
		printf("RIGHT\n");
		return 0;
	}else{
		bool f=false;
		for(int k=0;k<3;k++){
			for(int i=0;i<4;i++){
				x[k]+=dir[i][0];
				y[k]+=dir[i][1];
				if(isper(x,y)){
					f=true;
					printf("ALMOST\n");
					return 0;
				}
				x[k]-=dir[i][0];
				y[k]-=dir[i][1];
			}
		}
		printf("NEITHER\n");
	}
    return 0;
}

