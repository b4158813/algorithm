#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define maxm 55
#define maxn 1005

char ans[maxn];
char a[maxm][maxn];
char dess[maxm];
int main(){
	int T;
	char des[4]={'A','G','C','T'};
	cin>>T;//case number
	memset(a,0,sizeof(a));
	while(T--){
		dess['A']=0;
		dess['G']=0;
		dess['C']=0;
		dess['T']=0;
		int m,n;
		scanf("%d %d",&m,&n);
		getchar();
		for(int i=0;i<m;i++) scanf("%s",a[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				dess[a[j][i]]++;
			}
			int max=dess[des[0]];
			char maxc=des[0];
			for(int k=1;k<4;k++){
				if(dess[des[k]]>max){
					max=dess[des[k]];
					maxc=des[k];
				}
			}
			ans[i]=maxc;
			dess['A']=0;
			dess['G']=0;
			dess['C']=0;
			dess['T']=0;
		}
		printf("%s",ans);
	}
	return 0;
}
