#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],b[100005],f[100005],fun[100005]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),fun[a[i]]=i;
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int len=0;
	for(int i=1;i<=n;i++){
		if(fun[b[i]]>f[len]) f[++len]=fun[b[i]];
		else{
			int pos=lower_bound(f+1,f+1+len,fun[b[i]])-f;
			f[pos]=fun[b[i]];
		}
	}
	printf("%d\n",len);
	return 0;
}
