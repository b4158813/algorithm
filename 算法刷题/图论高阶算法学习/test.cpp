#include<bits/stdc++.h>
using namespace std;
int f[1000005][22],x[1000005],ans[1000005];
int n,k;
void ST_work()
{
    for(int i=1; i<=n; i++)
        f[i][0]=i;//�ȳ�ʼ��Ϊ����
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            int a=f[i][j-1],b=f[i+(1<<(j-1))][j-1];
            if(x[a]>=x[b])//����һ��Ҫע�⣬һ���Ǵ��ڵ��ڣ���Ϊ�����������ȣ�����Ҫѡǰ��һ����������֤�����Ǹ�һ����С��������ҪʱҲ�ܱ�ѡ��
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
    if(x[a]>=x[b])//ͬ��
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
            s=c+1;//�Ӻ�����
            e++;//βָ��Ҳ���ƣ����ƻ�������
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

