#include<bits/stdc++.h>
using namespace std;
int cnt,phi[10005],f[10005],prime[10005],from[10005];
inline void euler(int n){
    phi[1]=1; //ŷ����������
    f[0]=f[1]=1; //0��1����������
    for(int i=2;i<=n;i++){
        if(f[i]==0){ //�������������
            prime[++cnt]=i; //������������
            phi[i]=i-1; //���1
        }
        for(int j=1;j<=cnt&&i*prime[j]<=n;j++){ //ŷ��ɸ���Ĵ���
            f[i*prime[j]]=1; //ɸȥ
            from[i*prime[j]]=prime[j];
            if(i%prime[j]==0){
                //���2
                phi[i*prime[j]]=phi[i]*prime[j]; 
                break; //����
            }else{
                //���3��ŷ�������Ƕ��������Ļ��Ժ���
                phi[i*prime[j]]=phi[i]*phi[prime[j]];
            }
        }
    }
}
int main(){
	int n;
	cin>>n;
	euler(n);
	int x;
	while(cin>>x){
		while(from[x]!=0){
			cout<<from[x]<<" ";
			x/=from[x];
		}
		cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
