#include<bits/stdc++.h>
using namespace std;
int f[10000000]={};
int c[10000000]={};
int main()
{
    int n=0;
    int num[10]={0,1,2,3,5,10,20};//�Ƚ������С����Ԥ����
    for (int i=1;i<=6;i++)
    {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++) 
            c[++n]=num[i];
    }//ת��01����
    f[0]=1;
    int sum=0,ans=0;
    for (int i=1;i<=n;i++)
        sum+=c[i];//���01����������ֵ
    for (int i=1;i<=n;i++)
        for (int j=sum;j>=c[i];j--)
            f[j]+=f[j-c[i]];//DP
    for (int i=1;i<=sum;i++)
        if (f[i]) ans++;//�ۼ����п��ܳ��ֵķ����ܺ�
    cout<<"Total="<<ans;
    return 0;
}
