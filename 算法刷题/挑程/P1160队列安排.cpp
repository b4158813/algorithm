#include<bits/stdc++.h>
using namespace std;

struct node{
	int L,R;
}q[100005];
int n;
void add_left(int pos, int x){
	q[x].R = pos;
	q[x].L = q[pos].L;
	q[q[pos].L].R = x;
	q[pos].L = x;
}
void add_right(int pos, int x){
	q[x].L = pos;
	q[x].R = q[pos].R;
	q[q[pos].R].L=x;
	q[pos].R = x;
}
void erase(int x){
	if(q[x].L==-1) return;
	q[q[x].L].R = q[x].R;
	q[q[x].R].L = q[x].L;
	q[x].L=-1;
	q[x].R=-1;
}
void init(){
	for(int i=1;i<=n;i++){
		q[i].L=q[i].R=-1;
	}
	q[0].R=1;
	q[1].L=0;
	q[1].R=-1;
}
int main(){
	cin>>n;
	init();
	for(int i=2;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(y==1) add_right(x,i);
		else add_left(x,i);
	}
	int m;
	cin>>m;
	while(m--){
		int x;
		cin>>x;
		erase(x);
	}
	int x = q[0].R;
	while(1){
		cout<<x<<" ";
		if(q[x].R==-1) break;
		x=q[x].R;
	}
	return 0;
} 
