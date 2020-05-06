#include<iostream>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

map<set<int>,int> idcase;
vector<set<int> > setcase;

int ID(set<int> x){
    if(idcase[x]) return idcase[x];
    setcase.push_back(x);
    return idcase[x]=setcase.size()-1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        stack<int> s;
        int n;
        cin>>n;
        while(n--){
            string op;
            cin>>op;
            if(op=="PUSH")
                s.push(ID(set<int> ()));
            else if(op=="DUP")
                s.push(s.top());
            else{
                set<int> x1=setcase[s.top()];s.pop();
                set<int> x2=setcase[s.top()];s.pop();
                set<int> x3;
                if(op=="UNION")
    				set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x3,x3.begin()));
                if(op=="INTERSECT")
                	set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x3,x3.begin()));
                if(op=="ADD"){
                    x3=x2;
                    x3.insert(ID(x1));
                }
                s.push(ID(x3));
            }
                
        cout<<setcase[s.top()].size()<<endl;    
        }
        cout<<"***"<<endl;
    }
    return 0;
}

