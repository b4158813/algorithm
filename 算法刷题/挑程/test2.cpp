#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int dp[5050][55];
int num[201];
void add(int x,int k,int w,int v)
{
    int i;
    int t1,t2;
    t1=t2=1;
    for(i=1;i<=k;i++)
    {
        if(dp[x][t1]>dp[x-w][t2]+v)
        {
            num[i]=dp[x][t1];
            t1++;
        }
        else
        {
            num[i]=dp[x-w][t2]+v;
            t2++;
        }
    }
    for(i=1;i<=k;i++)dp[x][i]=num[i];
}
int main()
{
    int i,j,k,v,n;
    int ws[301];
    int vs[301];
    while(~scanf("%d%d%d",&k,&v,&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&ws[i],&vs[i]);
        }
        for(i=0;i<=v;i++)
        {
            for(j=0;j<=k;j++)
            {
                dp[i][j]=-99999999;
            }
        }
        //for(i=0;i<=v;i++)dp[i][0]=-1;
        dp[0][1]=0;
        for(i=0;i<n;i++)
        {
           // cout<<"-------------"<<endl;
            for(j=v;j>=ws[i];j--)
            {
                add(j,k,ws[i],vs[i]);
            }
        }
        int ns=0;
        for(i=1;i<=k;i++)
        {
            if(dp[v][i]<=0)break;
            ns+=dp[v][i];
        }
        cout<<ns<<endl;
    }
    return 0;
}
