#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=2147483647;
const int maxn = 10000;
const int N=500005,M=500005;
struct Edge{
	int u,v,w,next;
}e[M];
int cnt,head[N];
inline void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v,int w=0){
	e[++cnt]=Edge{u,v,w,head[u]};
	head[u]=cnt;
}
bool cmp(Edge x1,Edge x2){
	return x1.w<x2.w;
}
int fa[M],n,k,a[N],ans,you;

inline void kruskal(){
	sort(e+1,e+1+k,cmp);
	for(int i=1;i<=k;i++){
		int eu=e[i].u,ev=e[i].v;
		if(a[eu]>a[ev]&&!fa[ev]){
			fa[ev]=1;
			ans+=e[i].w;
			you++;
		}
	}
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	kruskal();
	if(you==n-1) printf("%d\n",ans);
	else printf("-1\n");
    return 0;
}

