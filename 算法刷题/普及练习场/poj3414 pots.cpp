#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int a,b,c;
int vis[105][105];
int ans;

struct node{
	int step,w1,w2;
	string ope;
};

void bfs(){
	queue <node> q;
	node hh;
	hh.ope="";
	hh.step=0;
	hh.w1=0;
	hh.w2=0;
	q.push(hh);
	while(!q.empty()){
		node q1=q.front();
		q.pop();
		if(q1.w1==c||q1.w2==c){
			ans=q1.step;
			cout<<ans<<endl<<q1.ope<<endl;
			return;
		}
		
		for(int i=0;i<6;i++){
			node v;
			if(i==0){//fill 1
				v.w1=a;
				v.w2=q1.w2;
				v.ope=q1.ope+"FILL(1)\n";
			}else if(i==1){//fill 2
				v.w1=q1.w1;
				v.w2=b;
				v.ope=q1.ope+"FILL(2)\n";
			}else if(i==2){//drop 1
				if(q1.w1!=0){
					v.w1=0;
					v.w2=q1.w2;
					v.ope=q1.ope+"DROP(1)\n";
				}
			}else if(i==3){//drop 2
				if(q1.w2!=0){
					v.w1=q1.w1;
					v.w2=0;
					v.ope=q1.ope+"DROP(2)\n";
				}
			}else if(i==4){//pour 1->2
				if(q1.w1!=0&&q1.w1+q1.w2<=b){
					v.w1=0;
					v.w2=q1.w2+q1.w1;
					v.ope=q1.ope+"POUR(1,2)\n";
				}else if(q1.w1!=0&&q1.w1+q1.w2>b){
					v.w1=q1.w1-(b-q1.w2);
					v.w2=b;
					v.ope=q1.ope+"POUR(1,2)\n";
				}
			}else if(i==5){
				if(q1.w2!=0&&q1.w1+q1.w2<=a){
					v.w2=0;
					v.w1=q1.w2+q1.w1;
					v.ope=q1.ope+"POUR(2,1)\n";
				}else if(q1.w2!=0&&q1.w1+q1.w2>a){
					v.w2=q1.w2-(a-q1.w1);
					v.w1=a;
					v.ope=q1.ope+"POUR(2,1)\n";
				}
			}
			if(!vis[v.w1][v.w2]){
				v.step=q1.step+1;
				vis[v.w1][v.w2]=1;
				q.push(v);
			}
		}
	}
	cout<<"impossible"<<endl;
	return;
}

int main(){
	cin>>a>>b>>c;
	bfs();
	return 0; 
}
