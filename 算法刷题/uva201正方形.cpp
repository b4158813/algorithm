#include<bits/stdc++.h>
using namespace std;
#define maxn 10


int hpos[maxn][maxn],vpos[maxn][maxn];
int sizenum[maxn];

int issquare(int i,int j,int len){
	int z,x;
	for(int z=j;z<j+len;++z) if(!hpos[i][z]) return 0;
	for(int z=j;z<j+len;++z) if(!hpos[i+len][z]) return 0;
	for(int x=i;x<i+len;++x) if(!vpos[x][j]) return 0;
	for(int x=i;x<i+len;++x) if(!vpos[x][j+len]) return 0;
	return 1;
}

int main(){
	int n,m,T=0,C=0;
	while(cin>>n){
		cin>>m;
		if(C) cout<<"\n**********************************\n"<<endl;
		C++; 
		memset(hpos,0,sizeof(hpos));
		memset(vpos,0,sizeof(vpos));
		memset(sizenum,0,sizeof(sizenum));
		char t;
		int x,y; 
		while(m--){
			cin>>t>>x>>y;
			if(t=='H'){
				hpos[x][y]=1;
			}
			if(t=='V'){
				vpos[y][x]=1;
			}
		}
		
//		for(int i=1;i<=4;i++)
//			for(int j=1;j<=4;j++){
//				if(hpos[i][j]) cout<<i<<j<<endl;
//				if(vpos[i][j]) cout<<i<<j<<endl;
//			}

//		cout<<"\n\n";
//		for(int i=1;i<=4;i++)
//			for(int j=1;j<=4;j++)
//				cout<<hpos[i][j]<<endl<<vpos[i][j]<<endl;
//		cout<<"\n\n";
		int len;
		for(len=1;len<=n;++len){
			int i,j;
			for(i=1;i<=n;++i){
				for(j=1;j<=n;++j){
					if(issquare(i,j,len)){
						sizenum[len]++;
					}
				}
			}
		}
//		cout<<"\n\n";
//		for(int i=0;i<10;i++)cout<<sizenum[i]<<endl;
//		cout<<"\n\n";
//		
		bool flag=false;
		for(int i=0;i<10;i++){
			if(sizenum[i]) flag=true;
		}
		printf("Problem #%d\n\n",++T);
		if(flag){
			for(int i=1;i<10;i++){
				if(sizenum[i]!=0)
					printf("%d square (s) of size %d\n",sizenum[i],i);
			}
		}
		else cout<<"No completed squares can be found."<<endl;
	}
	return 0;
}
