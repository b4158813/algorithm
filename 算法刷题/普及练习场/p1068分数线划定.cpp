#include<bits/stdc++.h>
using namespace std;

struct p{
	int num,score;
};

p pe[5005];

bool cmp(p p1,p p2){
	if(p1.score>p2.score) return true;
	else if(p1.score==p2.score){
		if(p1.num<p2.num) return true;
		else return false;
	}
	else return false;
}

int main(){
	int n,m;
	cin>>n>>m;
	int rs = m*1.5;
	for(int i=0;i<n;i++) 
		cin>>pe[i].num>>pe[i].score;
	sort(pe,pe+n,cmp);
	int fsx = pe[rs-1].score;
	for(int i=rs;i<n;i++){
		if(pe[i].score==fsx) rs++;
		if(pe[i].score<fsx) break;
	}
	cout<<fsx<<" "<<rs<<endl;
	for(int i=0;i<rs;i++){
		cout<<pe[i].num<<" "<<pe[i].score<<endl;
	}
	return 0;
}
