#include<bits/stdc++.h>
using namespace std;
char ans[1000005];
int main(){
	string a,b;
	cin>>a>>b;
	int lena=a.length(),lenb=b.length();
	if(a==b){
		cout<<"0"<<endl;
		return 0;
	}
	bool f=false;
	if(lena>lenb){
		f=true;
	}else if(lena<lenb||a<b){
		swap(a,b);
	}else if(a>=b){
		f=true;
	}
	for(int i=lenb;i<=lena;i++){
		b="0"+b;
	}
	int temp=0;
	int cnt=0;
	for(int i=lena-1;i>=0;i--){
		int cha=a[i]-b[i]-temp;
		if(cha<0){
			cha+=10;
			temp=1;
		}else temp=0;
		ans[++cnt]=cha+'0';
	}
	if(!f) cout<<"-";
	while(ans[cnt]=='0') --cnt;
	for(int i=cnt;i>=1;i--) cout<<ans[i];
	cout<<endl;
	return 0;
}
