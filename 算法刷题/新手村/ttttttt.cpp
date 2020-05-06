#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[30],y[30],xy[30],yx[30];
//x表示行，y表示列，
//xy表示向右上方倾斜的对角线，yx表示向左上方倾斜的对角线 
int n,ans=0;//n是棋盘的n，ans是解的个数； 

void dfs(int k){//深搜，输入行数 
	if(k>n){//如果把棋盘每行都填了，就输出此刻的答案 
		if(ans<=2){//只输出前三组数据 
			for(int p=1;p<=n;p++)
				cout<<x[p]<<" ";//题目要求按行输出列数 
			cout<<endl;//换行 
		}
		ans++;//只输出前三组数据 ，但是总数还是要继续加 
		return;//返回 
	}
	for(int i=1;i<=n;i++){
		if((!y[i])&&(!xy[k+i])&&(!yx[k-i+n])){//如果列、两个对角线都没有被占领 
			x[k]=i;//保存此刻行数所对应的的列数 
			y[i]=1;//占领对应的列、对角线 
			xy[k+i]=1;
			yx[k-i+n]=1;
			dfs(k+1);//递归 
			y[i]=0;//回溯，把这一步的占领全撤回 
			xy[k+i]=0;
			yx[k-i+n]=0;
		}
	}
}

int main()
{
//	while(cin>>n>>k){
	cin>>n;
	dfs(1);//第一个皇后 
	cout<<ans<<endl;//输出总个数 
	//}
	return 0;
}
