#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll u,v;
	scanf("%lld%lld",&u,&v);
	if(u==0&&v==0){
		printf("0\n");
		return 0;
	}
	if(u>v||(v-u)%2){
		printf("-1\n");
		return 0;
	}
	ll yu=(v-u)>>1;
	if(u==v){
		printf("1\n%lld\n",u);
		return 0;
	}
	if((yu&u)==0){
		printf("2\n%lld %lld\n",u+yu,yu);
		return 0;
	}
	printf("3\n%lld %lld %lld\n",u,yu,yu);
	return 0;
}
