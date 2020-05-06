#include<bits/stdc++.h>
using namespace std;
double p[25];
int main(){
	int n;
	while(cin>>n){
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			scanf("%lf",&p[i]);
		}
		double ans=0;
		for(int i=1;i<(1<<n);i++){
			int cnt=0;
			double sum=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					cnt++;
					sum+=p[j];
				}
			}
			if(cnt&1) ans+=1/sum;
			else ans-=1/sum;
		}
		printf("%.4lf\n",ans);
	}
	return 0;
}
