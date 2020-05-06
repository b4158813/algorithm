#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m[100][100][100];

ll w(ll a,ll b,ll c){
	if(a<=0||b<=0||c<=0) return 1;
	else if(m[a][b][c]!=0) return m[a][b][c];
	else if(a>20||b>20||c>20) m[a][b][c] = w(20,20,20);
	else if(a<b&&b<c) m[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else m[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	return m[a][b][c];
}

int main()
{
	
	int a,b,c;
	while(cin>>a>>b>>c){
		//memset(m,0,sizeof(m));
		if(a==-1&&b==-1&&c==-1) break;
		printf("w(%d, %d, %d) =",a,b,c);
		if(a>20) a=21;
		if(b>20) b=21;
		if(c>20) c=21;
		printf(" %lld\n",w(a,b,c));
	}
	return 0;
}
