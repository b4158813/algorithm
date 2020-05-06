#include<bits/stdc++.h>
using namespace std;
int f[10000000]={};
int c[10000000]={};
int main()
{
    int n=0;
    int num[10]={0,1,2,3,5,10,20};//先将砝码大小进行预处理
    for (int i=1;i<=6;i++)
    {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++) 
            c[++n]=num[i];
    }//转换01背包
    f[0]=1;
    int sum=0,ans=0;
    for (int i=1;i<=n;i++)
        sum+=c[i];//求出01背包体积最大值
    for (int i=1;i<=n;i++)
        for (int j=sum;j>=c[i];j--)
            f[j]+=f[j-c[i]];//DP
    for (int i=1;i<=sum;i++)
        if (f[i]) ans++;//累加所有可能出现的方案总和
    cout<<"Total="<<ans;
    return 0;
}
