#include<bits/stdc++.h>
using namespace std;

struct p{
	int x,y,num;
} s[500];

bool cmp(p r,p t){
	return r.num>t.num;
}

int main(){
	int m,n,k,c,cnt=0,cn=0,sum=0;
	bool f=false;
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			if(c!=0){
				s[cnt].num=c;
				s[cnt].x=i;
				s[cnt].y=j;
				cnt++;
			}
		}
	}
	sort(s,s+cnt+1,cmp);
//	for(int i=0;i<cnt;i++){
//		cout<<s[i].num<<endl;
//	}
	s[cnt].x=0;
	s[cnt].y=s[cnt-1].y;
	s[cnt].num=0;
	cn+=s[0].x;
//	sum+=s[0].num;
	for(int i=1;i<=cnt;i++){
		sum+=s[i-1].num;
		cn+=s[i-1].x+1;
	//	cout<<sum<<endl; 
	//	cout<<cn<<endl;
		if(cn>k) {
			sum-=s[i-1].num;
			cout<<sum;break;
		}
	//	sum+=s[i].num;
		cn-=s[i-1].x+1;
		cn+=abs(s[i].x-s[i-1].x)+abs(s[i].y-s[i-1].y)+1;
		if(i==cnt) f=true;
	}
	if(f) cout<<sum;
	return 0;
}
