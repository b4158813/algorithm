#include<bits/stdc++.h>
using namespace std;

string s[25];
int n;
int vis[25];
int mlen[25][25];
int maxl=0,ans=0;
bool f=false;
int search(string s1, string s2){//���ع����ַ�����������̳��� 
	f=false;
	int m2,q2,len=0;
	//��������Ϊ���ҵ�s2�е�һ����s1���һ���ַ���ͬ���ַ� 
	for(int i=s1.length()-1;i>=0;i--){//s1�Ӻ���ǰ���� 
		if(!f){//�����û�ҵ� 
			for(int j=0;j<s2.length();j++){//s2��ǰ������� 
				if(s1[i]==s2[j]){
					m2=j;//��¼���ܵĳ��� 
					f=true;//���Ϊ�ҵ��� 
					break;//�˳�ѭ�� 
				}
			}
		}
		q2=m2-(s1.length()-1-i);//�����¼һ��s2��s1��ӦҪ�Ƚϵ�λ�ã������Լ�ģ��һ�� 
		if(s1[i]==s2[q2]) {//һ����ͬ 
			if(q2==0) return m2+1;//�ҵ��˵ڶ����ַ����ĵ�һ��λ�ã��ͷ��س��� 
		}
		else return 0;//ֻҪ���ֲ���ͬ���ͷ���0 
	}
	return 0;
}

void dfs(int i){//���� 
	bool jx=false;
	for(int j=1;j<=n;j++){
		if(vis[j]>=2) continue;
		if(!mlen[i][j]) continue;
		if(s[i].length()==mlen[i][j]||s[j].length()==mlen[i][j]) continue;
		vis[j]++;
		jx=true;
		ans+=s[j].length()-mlen[i][j];
		dfs(j);
		ans-=s[j].length()-mlen[i][j];
		vis[j]--;
	}
	if(!jx){
		maxl=max(maxl,ans);
	}
	return;
}

int main(){
	memset(vis,0,sizeof(vis));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	char c;
	cin>>c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mlen[i][j]=search(s[i],s[j]);
		}
	}
//	printf("\n%d\n",mlen[3][3]); 
	for(int i=1;i<=n;i++){
		if(s[i][0]==c){
			vis[i]++;
			ans=s[i].length();
			dfs(i);
			vis[i]=0;
		}
	}
	cout<<maxl<<endl;
	return 0;
}
