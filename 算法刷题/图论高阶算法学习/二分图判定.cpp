#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
inline ll read() { 
	ll kk=0,f=1; 
	char cc=getchar(); 
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();} 
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();} 
	return kk*f; 
}
struct Edge{
	int v,next;
}e[500025];
int n,m,cnt,head[500025],col[500025];
inline void addedge(int u,int v){
	e[cnt]=Edge{v,head[u]};
	head[u]=cnt++;
}
bool judge(int u,int c){
	col[u]=c;
	for(int i=head[u];~i;i=e[i].next){
		int v=e[i].v;
		if(col[v]==col[u]) return false;
		else if(col[v]==0&&!judge(v,3-c)) return false;
	}
	return true;
}
inline void init(){
	cnt=0;
	memset(col,0,sizeof(col));
	memset(head,-1,sizeof(head));
}
int main(){
	int t=read();
	while(t--){
		init();
		n=read(),m=read();
		int u,v;
		for(int i=1;i<=m;i++){
			u=read(),v=read();
			addedge(u,v);
			addedge(v,u);
		}
		bool f=true;
		for(int i=1;i<=n;i++){
			if(col[i]==0){
				if(!judge(i,1)){
					f=false;
					break;
				}
			}
		}
		if(f) printf("Correct\n");
		else printf("Wrong\n");
	}
	return 0;
}
