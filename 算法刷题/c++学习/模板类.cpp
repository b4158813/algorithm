#include<bits/stdc++.h>
using namespace std;

template <typename T1,typename T2,typename T3>
class Operator{
	public:
		T1 add(T2 a,T3 b){
			return a+b;
		}
		T1 minus(T2 a,T3 b);
};

// �����ⲿ�����Ա���� 
template <typename T1,typename T2,typename T3>
T1 Operator<T1,T2,T3>::minus(T2 a,T3 b){
	return a-b;
}

// ����string�ļ������� 
string operator-(string &s1, string &s2){
	return "minus";
} 

template <typename T> //�����ػ� 
class Operator<T,T,T>{ //ֻ�������Ͷ���ͬʱ���� 
	public:
		T add(T a,T b){
			return a+b;
		}
};


template <> //��ȫ�ػ� 
class Operator<int,int,int>{ //������ĿҪһ�£�ֻ���ڶ���intʱ���� 
	public:
		int add(int a,int b){
			return a+b;
		} 
};

int main(){
	Operator<string,string,string> s;
	cout<<s.add("abc","dfs")<<endl;
	cout<<s.minus(1,2)<<endl; 
	
	Operator<float,float,float> b;
	cout<<b.add(1.2,3.5)<<endl;
	
	Operator<int,int,int> a;
	cout<<a.add(2,5);
	 
}
