#include<bits/stdc++.h>
using namespace std;

string s[25];
int n;
int vis[25];
int mlen[25][25];
int maxl=0,ans=0;
bool f=false;
int search(string s1, string s2){//返回公两字符串共部分最短长度 
	f=false;
	int m2,q2,len=0;
	//下面这是为了找到s2中第一个与s1最后一个字符相同的字符 
	for(int i=s1.length()-1;i>=0;i--){//s1从后往前遍历 
		if(!f){//如果还没找到 
			for(int j=0;j<s2.length();j++){//s2从前往后遍历 
				if(s1[i]==s2[j]){
					m2=j;//记录可能的长度 
					f=true;//标记为找到了 
					break;//退出循环 
				}
			}
		}
		q2=m2-(s1.length()-1-i);//这里记录一下s2与s1对应要比较的位置，可以自己模拟一下 
		if(s1[i]==s2[q2]) {//一旦相同 
			if(q2==0) return m2+1;//且到了第二个字符串的第一个位置，就返回长度 
		}
		else return 0;//只要出现不相同，就返回0 
	}
	return 0;
}

void dfs(int i){//深搜 
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
