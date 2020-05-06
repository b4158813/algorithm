#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Edge{
	int u,v,w,next;
	bool f;
}e[50005];
int cnt,head[50005];
void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}
inline void addedge(int u,int v,int w=0){
	e[cnt]=Edge{u,v,w,head[u],false};
	head[u]=cnt++;
}
stack<int> sta;
void dfs(int u){
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(!e[i].f){
			e[i].f=1;
			dfs(v);
		}
	}
	sta.push(u);
}
int main(){
	cin>>n;
	if(n==1){
		cout<<"01"<<endl;
		return 0;
	}
	init();
	int k=(1<<n-2)-1;
	for(int i=0;i<1<<n-1;i++){
		int giao=i&k;
		for(int j=0;j<1<<n-1;j++){
			if(giao==j>>1){
				addedge(i,j);
			}
		}
	}
	
	dfs(0);
	sta.pop();
	while(sta.size()){
		cout<<(sta.top()&1);
		sta.pop();
	}
	return 0;
}
