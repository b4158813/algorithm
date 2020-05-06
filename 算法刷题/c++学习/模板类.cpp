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

// 在类外部定义成员函数 
template <typename T1,typename T2,typename T3>
T1 Operator<T1,T2,T3>::minus(T2 a,T3 b){
	return a-b;
}

// 重载string的减法运算 
string operator-(string &s1, string &s2){
	return "minus";
} 

template <typename T> //部分特化 
class Operator<T,T,T>{ //只有在类型都相同时采用 
	public:
		T add(T a,T b){
			return a+b;
		}
};


template <> //完全特化 
class Operator<int,int,int>{ //参数数目要一致，只有在都是int时采用 
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
