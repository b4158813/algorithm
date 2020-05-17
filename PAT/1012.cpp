#include<bits/stdc++.h>
using namespace std;;
const int maxn=2005;

int n,m;
unordered_map<string,int> ma;
struct node
{
	string id;
	double t[4];
	int num;
}x[maxn];

string cc="ACME";

bool cmp(node s1,node s2){
	if(s1.t[0]==s2.t[0]&&s1.t[1]==s2.t[1]&&s1.t[2]==s2.t[2]) return s1.t[3]>s2.t[3];
	if(s1.t[0]==s2.t[0]&&s1.t[1]==s2.t[1]) return s1.t[2]>s2.t[2];
	if(s1.t[0]==s2.t[0]) return s1.t[1]>s2.t[1];
	return s1.t[0]>s2.t[0];
}

inline void solve(int xx){
	for(int i=1;i<=n;i++){
		if(x[i].num==xx){
			cout<<i<<" ";
			int tp=0,atp=0;
			for(int j=0;j<4;j++){
				if(x[i].t[j]>tp) {
					tp=x[i].t[j];
					atp=j;
				}
			}
			cout<<cc[atp]<<endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i].id>>x[i].t[1]>>x[i].t[2]>>x[i].t[3];
		x[i].t[0]=(x[i].t[1]+x[i].t[2]+x[i].t[3])/3;
		x[i].num=i;
		ma[x[i].id]=i;
	}
	sort(x+1,x+1+n,cmp);
	string tp;
	for(int i=1;i<=m;i++){
		cin>>tp;
		int id=ma[tp];
		if(id==0) cout<<"N/A"<<endl;
		else solve(id);
	}
	return 0;
}