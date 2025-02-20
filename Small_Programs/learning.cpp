#include <iostream>
#include <queue>
using namespace std;
int f1();
f1(){

cout<<"hello";
}
template<typename T , int size>
struct emp{
int n = 0;
int arr[size];

string name = "marwan";
};

template<class T>
void fun(T a) {
	cout << "[" << a << "]";
}

template<>
void fun(string str) {
	cout << "{{" << str << "}}";

	cout<< str.size();
}

int main (){
emp<int , 12> emp1;
//emp1.n+=2;
//cout<<emp1.n;
//emp emp2;
//emp2.n = emp2.n+1;
//cout<<emp2.n;
//emp1.size = 12;
fun(10.5), fun("mostafa");
return 0;
}
