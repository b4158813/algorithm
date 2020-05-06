#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define maxn 10

int main(){
    int r,c,count=1;
    while((scanf("%d",&r)==1)&&r){
        scanf("%d",&c);
        char a[maxn][maxn];
        int b[maxn][maxn];
        int num=1;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>a[i][j];
    	/* 
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                {cout<<a[i][j];
                if(j==c-1) cout<<endl;}
        */
        cout<<"puzzle #"<<count++<<":"<<endl;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(a[i][j]=='*') continue;
                if((a[i-1][j]=='*')||(a[i][j-1]=='*')||i==0||j==0)
                    {b[i][j]=num++;continue;}
                else if(a[i][j]=='*') b[i][j]=0;
                else b[i][j]=-1;
            }
            
        /*for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                {cout<<b[i][j];
                if(j==c-1) cout<<endl;}
        */
        
        //打印across 
        cout<<"Across"<<endl<<"  ";
        for(int i=0;i<r;i++){
            int flag1=0,flag2=1;
            for(int j=0;j<c;j++){
                if(a[i][j]=='*') continue;
                flag1=j;
                cout<<b[i][flag1]<<".";
                if(j==c-1){cout<<a[i][j]<<endl<<"  ";break;}
                int k=j+1;
                while(a[i][k]>='A'&&a[i][k]<='Z') k++;
                flag2=k;
                for(int l=j;l<k;l++)
                    cout<<a[i][l];
                if(i==r-1){//判断是不是最后一个，如果是，则输出换行，直接退出 
                	int nb=k;
                	while(++nb=='*');
                	if(nb>=c-1) {cout<<endl;break;}
				}
                cout<<endl<<"  ";
                j=k;
            }
        }//打印down 
        cout<<"Down"<<endl<<"  ";
        for(int i=0;i<c;i++){
            int flag1=0,flag2=1;
            for(int j=0;j<r;j++){
                if(a[j][i]=='*') continue;
                flag1=j;
                cout<<b[flag1][i]<<".";
                if(j==r-1){cout<<a[j][i]<<endl<<"  ";break;}
                int k=j+1;
                while(a[k][i]>='A'&&a[k][i]<='Z') k++;
                flag2=k;
                for(int l=j;l<k;l++)
                    cout<<a[l][i];
            	if(i>=c-1&&j>=r-1){cout<<endl;break;}
                cout<<endl<<"  ";
                j=k;
            }
        }
    	cout<<endl;
    }
    
    return 0;
}     


