//niiick
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

const int maxn=1100010;
int n,ans=2e9;
int dp[maxn][25];
int rem[25][25];

int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    rem[i][j]=read();

    memset(dp,67,sizeof(dp));
    dp[1][1]=0;//״̬1��ʾ��ʱֻ��1�ŵ���ʹ�

    for(int i=0;i<=(1<<n)-1;++i)//dp���̽�������
    for(int j=1;j<=n;++j)
    if( ( (1<<j-1)&i )==0 )
    for(int k=1;k<=n;++k)
    if( ( (1<<k-1)&i) )
    dp[i|(1<<j-1)][j]=min(dp[i|(1<<j-1)][j],dp[i][k] + rem[k][j]);

    for(int i=2;i<=n;i++)//����״̬(1<<n)-1��������ȫΪ1����Ѱ�ҵ�1��̵ĵ�
    ans=min(ans,dp[(1<<n)-1][i] + rem[i][1]);

    printf("%lld",ans);
    return 0;
}
