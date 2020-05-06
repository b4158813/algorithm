#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long ll; 
const int maxn = 10005;
const int maxm = 15;
map <string,int> tb;
map <P,int> ltb;
string s;
int cnt[maxn][maxm];
int num = 0;
bool flag = true;

int main(){
	int n,m;
	char ch;
	while(cin>>n>>m){
		memset(cnt,0,sizeof(cnt));
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				getline(cin,s,',');
				if(!tb.count(s)) tb[s]=++num;
				cnt[i][j]=tb[s];
			}
			getline(cin,s,'\n');
			if(!tb.count(s)) tb[s]=++num;
				cnt[i][m]=tb[s];
		}
		/*
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			cout<<cnt[i][j]<<" ";
			if(j==m) cout<<endl;
		}
		*/
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				ltb.clear();
				for(int k=1;k<=n;k++){
					if(ltb.find(P(cnt[k][i],cnt[k][j]))!=ltb.end())
					{
						cout<<"NO"<<endl;
						cout<<ltb[P(cnt[k][i],cnt[k][j])]<<" "<<k<<endl;
						cout<<i<<" "<<j<<endl;
						goto exit;
					}
					else {
						ltb[P(cnt[k][i],cnt[k][j])]=k;
					}
				}
			}
		}
		cout<<"YES"<<endl;
		exit:;
	}
	return 0;
}
