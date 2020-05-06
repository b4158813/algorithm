#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
int n;

int main() {
    int T;
	scanf("%d",&T);
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		printf("%d\n",n<2?0:n-2);
	}
    return 0;
}

