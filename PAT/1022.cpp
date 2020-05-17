#include<bits/stdc++.h>
using namespace std;

map<string,set<int>> Title,Author,Key,Pub,Year;

int n,m;
string op,tp;

inline void query(map<string,set<int>> & ma,string &s){
	if(ma.find(s)==ma.end()){
		cout<<"Not Found"<<endl;
	}else{
		for(auto it=ma[s].begin();it!=ma[s].end();it++){
			printf("%07d\n",*it);
		}
	}
}
int main(){
	scanf("%d",&n);
	int id;
	string title,author,key,pub,year;
	for(int i=1;i<=n;i++){
		scanf("%d",&id);
		getchar();
		getline(cin,title);
		Title[title].insert(id);
		getline(cin,author);
		Author[author].insert(id);
		while(cin>>key){
			Key[key].insert(id);
			char c=getchar();
			if(c=='\n') break;
		}
		getline(cin,pub);
		Pub[pub].insert(id);
		getline(cin,year);
		Year[year].insert(id);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d: ",&k);
		getline(cin,op);
		string con=op;
		printf("%d: ",k);
		cout<<op<<endl;
		if(k==1)
			query(Title,con);
		if(k==2)
			query(Author,con);
		if(k==3)
			query(Key,con);
		if(k==4)
			query(Pub,con);
		if(k==5)
			query(Year,con);
	}
	return 0;
}