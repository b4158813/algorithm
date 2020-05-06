#include<bits/stdc++.h>
#define IL inline
#define RI register int
IL void in(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int a[108][18],f[2048],n,m;
int main()
{
    in(n),in(m);
    memset(f,0x3f,sizeof f);
    for(RI i=1;i<=m;i++)
        for(RI j=1;j<=n;j++)
            in(a[i][j]);
    f[(1<<n)-1]=0;//灯全开着的操作次数为0
    //printf("%d",(1<<n)-1); 
    for(RI i=(1<<n)-1;i>=0;i--)
    {
        for(RI j=1;j<=m;j++)
        {
            int now=i;
            for(RI l=1;l<=n;l++)
            {
                if(a[j][l]==0)continue;
                if(a[j][l]==1 and (i&(1<<(l-1)))) now^=(1<<(l-1));
                if(a[j][l]==-1 and !(i&(1<<(l-1)))) now^=(1<<(l-1));
            }
            f[now]=std::min(f[now],f[i]+1);
        }
    }
    printf("%d",f[0]==1061109567?-1:f[0]);
    //这个奇怪的数字就是memset 0x3f得出来的
    //并无什么其他意义
}
