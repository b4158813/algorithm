#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct P{
	int p,n;
} ansx[maxn],ansy[maxn];

bool cmp(P x, P y){
	return x.n>y.n;
}
bool cmp1(P x, P y){
	return x.p<y.p; 
}

int main(){
	int m,n,k,l,d;
	int ax,ay,bx,by;
	cin>>m>>n>>k>>l>>d;
	for(int i=0;i<d;i++){
		cin>>ax>>ay>>bx>>by;
		if(ax==bx){
			ansy[min(ay,by)].p=min(ay,by);
			ansy[min(ay,by)].n++;
		}
		else{
			ansx[min(ax,bx)].p=min(ax,bx);
			ansx[min(ax,bx)].n++;
		}
	}
	sort(ansy+1,ansy+n+1,cmp);
	sort(ansx+1,ansx+m+1,cmp);
	sort(ansx+1,ansx+k+1,cmp1);
	sort(ansy+1,ansy+l+1,cmp1);
	for(int i=1;i<=k;i++){
		cout<<ansx[i].p<<" ";
	}
	cout<<endl;
	for(int i=1;i<=l;i++){
		cout<<ansy[i].p<<" ";
	}
	return 0;
}
