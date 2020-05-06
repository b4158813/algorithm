#include<iostream>
using namespace std;
int n,x;
int v[11];
void prt(int i){
    for(int i=1;i<=n;i++)
        cout<<v[i];
    cout<<endl;
}
void dfs(int i){
    if(i>n){
        prt(n);
        return ;
    }
    for(int j=1;j<=n;j++){
        v[i]=j;
        dfs(i+1);
    }
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}
