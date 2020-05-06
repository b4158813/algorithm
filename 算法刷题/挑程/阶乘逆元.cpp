#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
const int mod=13;
int ifac[N],fac=1;
inline int get_inv(int x,int y){
    int base=x,ans=1;
    y-=2;
    while(y>0){
        if(y&1) ans=(ll)ans*base%mod;
        base=(ll)base*base%mod;
        y>>=1;
    }
    return ans;
}

int main(){
	int n;cin>>n;
	for(int i=2;i<=n;i++) 
    	fac=(ll)fac*i % mod;
	ifac[n]=get_inv(fac, mod);
	for(int i=n-1;i>=0;i--) 
   		ifac[i]=(ll)ifac[i+1]*(i+1)%mod;
   		
   	for(int i=1;i<=n;i++) cout<<ifac[i]<<endl;
   	return 0;
}



