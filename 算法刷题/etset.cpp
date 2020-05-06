#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
int n,m,a[35];
int ans[35];
int Sum[35];
bool vis[35];
bool f=0;
void dfs(int num,int x,int sum){
	if(f||sum+Sum[n]-Sum[num]<m||sum>m) return;
	if(sum==m){
		f=1;
		for(int i=1;i<x;i++){
			printf("%d ",ans[i]);
		}
		putchar('\n');
		return;
	}
	for(int i=num+1;i<=n;i++){
		ans[x]=a[i];
		dfs(i,x+1,sum+a[i]);
	}
}

int main() {
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) Sum[i]=Sum[i-1]+a[i];
    dfs(0,1,0);
    if(!f) printf("No Solution\n");
    return 0;
}

