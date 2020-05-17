#include<bits/stdc++.h>
using namespace std;

int k1,k2;
struct node
{
	int x;
	double y;
}a[1005],b[1005],d[1000005];

double c[1000005];
int cnt;

int main(){
	scanf("%d",&k1);
	for(int i=1;i<=k1;i++){
		scanf("%d%lf",&a[i].x,&a[i].y);
	}
	scanf("%d",&k2);
	for(int i=1;i<=k2;i++){
		scanf("%d%lf",&b[i].x,&b[i].y);
	}
	for(int i=1;i<=k1;i++){
		for(int j=1;j<=k2;j++){
			c[a[i].x+b[j].x]+=a[i].y*b[j].y;
		}
	}
	int ans=0;
	for(int i=1000005;i>=0;i--){
		if(c[i]!=0){
			ans++;
			d[++cnt].x=i;
			d[cnt].y=c[i];
		}
	}
	printf("%d ",ans);
	for(int i=1;i<cnt;i++){
		printf("%d %.1lf ",d[i].x,d[i].y);
	}
	printf("%d %.1lf",d[cnt].x,d[cnt].y);
	return 0;
}