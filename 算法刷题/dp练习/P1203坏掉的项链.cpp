#include<bits/stdc++.h>
using namespace std;
int n;
string s;

int main() {
    cin>>n>>s;
	int len=s.length();
    string t=s;
    reverse(t.begin(),t.end());
    s=t+s;
    int ans=0;
//    cout<<s.length()<<endl;
	cout<<s<<endl;
    for(int i=len;i<2*len;i++){
    	int z=i-1,y=i;
    	printf("z:%c,y:%c\n",s[z],s[y]);
    	char z1=s[z],y1=s[y];
    	if(z1=='w'){
    		int zz=z;
    		zz--;
    		while(s[zz]=='w') zz--;
    		z1=s[zz];
		}
    	if(y1=='w'){
    		int yy=y;
    		yy++;
    		while(s[yy]=='w') yy++;
    		y1=s[yy];
		}
    	z--,y++;
    	int temp=2;
    	while(z>0&&(s[z]==z1||s[z]=='w')){
    		temp++;
    		z--;
		}
//		printf("temp:%d\n",temp);
		while(y<2*len&&(s[y]==y1||s[y]=='w')){
			temp++;
			y++;
		}
//		printf("temp:%d\n",temp);
		ans=max(ans,min(temp,len));
	}
	cout<<ans<<endl;
    return 0;
}

