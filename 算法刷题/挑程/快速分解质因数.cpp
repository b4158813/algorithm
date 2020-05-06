#include<bits/stdc++.h>
using namespace std;
int cnt,phi[10005],f[10005],prime[10005],from[10005];
inline void euler(int n){
    phi[1]=1; //欧拉函数特例
    f[0]=f[1]=1; //0和1都不是素数
    for(int i=2;i<=n;i++){
        if(f[i]==0){ //如果该数是素数
            prime[++cnt]=i; //计入素数数组
            phi[i]=i-1; //情况1
        }
        for(int j=1;j<=cnt&&i*prime[j]<=n;j++){ //欧拉筛核心代码
            f[i*prime[j]]=1; //筛去
            from[i*prime[j]]=prime[j];
            if(i%prime[j]==0){
                //情况2
                phi[i*prime[j]]=phi[i]*prime[j]; 
                break; //核心
            }else{
                //情况3，欧拉函数是对于素数的积性函数
                phi[i*prime[j]]=phi[i]*phi[prime[j]];
            }
        }
    }
}
int main(){
	int n;
	cin>>n;
	euler(n);
	int x;
	while(cin>>x){
		while(from[x]!=0){
			cout<<from[x]<<" ";
			x/=from[x];
		}
		cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
