#include<bits/stdc++.h>
using namespace std;
int f[1000005][22],x[1000005],ans[1000005];
int n,k;
void ST_work()
{
    for(int i=1; i<=n; i++)
        f[i][0]=i;//先初始化为本身
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            int a=f[i][j-1],b=f[i+(1<<(j-1))][j-1];
            if(x[a]>=x[b])//这里一定要注意，一定是大于等于，因为如果两个数相等，我们要选前面一个，这样保证后面那个一样大小的数在需要时也能被选到
                f[i][j]=a;
            else
            {
                f[i][j]=b;
            }
        }
}
int ask(int l,int r)
{
    int n=log(r-l+1)/log(2);
    int a=f[l][n],b=f[r-(1<<n)+1][n];
    if(x[a]>=x[b])//同上
        return a;
    else
        return b;
}
int main()
{
    while(cin>>n>>k)
    {
        memset(f,0,sizeof(f));

        for(int i=1; i<=n; i++)
            scanf("%d",&x[i]);
        ST_work();
        int s=1,e=n-k+1,cot=0,c;
        while(k--)
        {
            c=ask(s,e);
            ans[cot++]=c;
            s=c+1;//从后面找
            e++;//尾指针也后移，类似滑动窗口
        }
        for(int i=0; i<cot; i++)
        {
            cout<<x[ans[i]];
            if(i!=cot-1)
                cout<<' ';
        }
        puts("");
    }
    return 0;
}

