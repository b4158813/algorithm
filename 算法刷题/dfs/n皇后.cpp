#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[30],y[30],xy[30],yx[30];
//x��ʾ�У�y��ʾ�У�
//xy��ʾ�����Ϸ���б�ĶԽ��ߣ�yx��ʾ�����Ϸ���б�ĶԽ��� 
int n,ans=0;//n�����̵�n��ans�ǽ�ĸ����� 

void dfs(int k){//���ѣ��������� 
	if(k>n){//���������ÿ�ж����ˣ�������˿̵Ĵ� 
		if(ans<=2){//ֻ���ǰ�������� 
			for(int p=1;p<=n;p++)
				cout<<x[p]<<" ";//��ĿҪ����������� 
			cout<<endl;//���� 
		}
		ans++;//ֻ���ǰ�������� ��������������Ҫ������ 
		return;//���� 
	}
	for(int i=1;i<=n;i++){
		if((!y[i])&&(!xy[k+i])&&(!yx[k-i+n])){//����С������Խ��߶�û�б�ռ�� 
			x[k]=i;//����˿���������Ӧ�ĵ����� 
			y[i]=1;//ռ���Ӧ���С��Խ��� 
			xy[k+i]=1;
			yx[k-i+n]=1;
			dfs(k+1);//�ݹ� 
			y[i]=0;//���ݣ�����һ����ռ��ȫ���� 
			xy[k+i]=0;
			yx[k-i+n]=0;
		}
	}
}

int main()
{
//	while(cin>>n>>k){
	cin>>n;
	dfs(1);//��һ���ʺ� 
	cout<<ans<<endl;//����ܸ��� 
	//}
	return 0;
}
