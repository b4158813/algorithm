#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define maxn 10005

int quo[maxn],res[maxn];
int main(){
	int m,n;
	while(cin>>m>>n&&m){
		memset(quo,0,sizeof(quo));
		memset(res,-1,sizeof(res));
		int a,b,count=0;
		a=m/n;b=m%n;b*=10;
		while(res[b]==-1){
			quo[count]=b/n;
			res[b]=count++;
			b%=n;
			b*=10;
		}
		int start_pos=res[b];
		printf("%d/%d = %d.",m,n,a);
		for(int i=0;i<start_pos;i++) printf("%d",quo[i]);
		cout<<"(";
		if(count-start_pos<=50){
			for(int i=start_pos;i<count;i++) cout<<quo[i];
		}
		else{
			for(int i=start_pos;i<count+50;i++) cout<<quo[i];
			cout<"...";
		}
		cout<<")\n";
		printf("  %d = number of digits in repeating cycle\n\n",count-start_pos);
	}
	return 0;
}
