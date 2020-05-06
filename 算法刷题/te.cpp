#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
inline int cal(int x){
	int ans=0;
	while(x){
		if(x%10==9) ans++;
		x/=10;
	}
	return ans;
}
int ans;
int main() {
    int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ans+=cal(i);
	}
	printf("%d\n",ans);
    return 0;
}

