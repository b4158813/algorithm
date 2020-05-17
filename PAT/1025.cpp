#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll id;
	int grade;
	int bel;
	int rank1,rank2;
}a[50005];

bool cmp(node x1,node x2){
	if(x1.grade==x2.grade) return x1.id<x2.id;
	return x1.grade>x2.grade;
}
int n,tot,k[205],cnt;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			++cnt;
			cin>>a[cnt].id>>a[cnt].grade;
			a[cnt].bel=i;
		}
	}

	for(int i=1;i<=n;i++){
		tot+=k[i];
		sort(a+1+tot-k[i],a+1+tot,cmp);
		int jia=0,ran=1;
		for(int j=1;j<=k[i];j++){
			if(j>1&&a[j+tot-k[i]].grade==a[j+tot-k[i]-1].grade){
				jia++;
			}else ran+=jia,jia=1;
			a[j+tot-k[i]].rank2=ran;
			// printf("id:%lld rank2:%d ",a[j+tot-k[i]].id,a[j+tot-k[i]].rank2);
			// printf("grade:%d \n",a[j+tot-k[i]].grade);
		}
	}

	printf("%d\n",tot);
	sort(a+1,a+1+tot,cmp);
	int jia=0,ran=1;
	for(int i=1;i<=tot;i++){
		if(i>1&&a[i].grade==a[i-1].grade) jia++;
		else ran+=jia,jia=1;
		a[i].rank1=ran;

		printf("%013lld %d %d %d\n",a[i].id,a[i].rank1,a[i].bel,a[i].rank2);
	}
	return 0;
}