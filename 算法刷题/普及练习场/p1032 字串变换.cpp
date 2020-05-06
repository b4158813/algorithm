#include<bits/stdc++.h>
using namespace std;

string original,final;
string a[10],b[10];
map<string,int> m;
int ans,n;

struct node{
	string str;
	int step;
};

string trans(string &st,int i,int j){
	string sss="";
	if(i+a[j].length()>st.length()) return sss;
	for(int k=0;k<a[j].length();k++){
		if(st[i+k]!=a[j][k]){
			return sss;
		}
	}
	sss=st.substr(0,i);
	sss+=b[j];
	sss+=st.substr(i+a[j].length());
	return sss;
}

void bfs(){
	queue <node> q;
	node s;
	s.step=0;
	s.str=original;
	q.push(s);
	while(!q.empty()){
		node u=q.front();
		q.pop();
		string temp;
		if(m.count(u.str)) continue;
		if(u.str==final){
			ans=u.step;
			break;
		}
		m[u.str]=1;
		for(int i=0;i<u.str.length();i++){
			for(int j=0;j<n;j++){
				temp=trans(u.str,i,j);
				if(temp!=""){
					node p;
					p.step=u.step+1;
					p.str=temp;
					q.push(p);
				}
			}
		}
	}
	
	if(ans>10||ans==0){
		cout<<"NO ANSWER!"<<endl;
	}
	else cout<<ans<<endl;
}

int main(){
	cin>>original>>final;
	n=0;
	while(cin>>a[n]>>b[n]){
		n++;
	}
	bfs();
	return 0;
}
 
