#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[10][3];
int s[maxn];

int main()
{	
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=m;i++) s[i]=i;
	int flag=0,num=0;
		for(int x=1;x<=m;x++){
			for(int y=1;y<=m;y++){
				for(int z=1;z<=m;z++){
					for(int i=0;i<n;i++){
						if((abs(a[i][0]-x)^abs(a[i][1]-y)^abs(a[i][2]-z))==9){
							//if(x==y&&y==z) continue;
							num++;
						}
					}
					if(num==n) cnt++;num=0;
				}
				}
			}
	cout<<cnt<<endl;
	return 0;
}
