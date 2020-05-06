/*
出处：Danzel♂
把圆看成线段，所以这题就是线段覆盖，然后答案是被完全覆盖的线段数+所有线段数+1
被完全覆盖的线段的数量就用递归找，不断的找被当前线段完全包含的线段，然后判断是否在里面
然后这道题有一种特殊情况可以不用执行程序，就是所有圆都是同心圆的时候，因为这种状态只存在重合和包含（本题重合不算完全覆盖），直接输出圆的数量+1即可
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#define maxn 300005
#define ll long long
using namespace std;

ll n,cnt,can,ans;
struct node{
    ll l,r;
}e[maxn];

ll read(){
    ll xx=0;ll ff=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}

int cmp(node a,node b){
    if(a.l==b.l ){
        return a.r>b.r;
    }return a.l<b.l;
}

int t;
int check (ll id){
    int now=e[id].l,add=1,ret=0;
    while(t!=n+1&&e[t].r<=e[id].r){
        if(e[t].l!=now)add=0;
        now=e[t].r;
        ret+=check(t++);
    }
    if(now!=e[id].r )add=0;
    return 1+ret+add;
}

int main(){
    n=read();
    for(ll i=1;i<=n;i++){
        ll x,R;
        x=read();R=read();
        e[i].l=x-R;e[i].r=x+R;
        if(cnt==0)cnt=x;
        if(cnt!=x)can=1;
    }
    if(!can){cout<<n+1;return 0;    }//同一个圆心可以不管了
    sort(e+1,e+n+1,cmp);t=1;
    while(t!=n+1){
        ans+=check(t++);
    } ans=ans+1;
    cout<<ans;
}
