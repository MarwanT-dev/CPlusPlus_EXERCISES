#include <bits/stdc++.h>
using namespace std;


int main(){
    string test = "hi abc abc abc abc";

    cout<<test.substr(3)<<endl; //this means that it will take the substring starting from pos 3
    cout<<test.substr(3,5)<<endl;//from pos 3 to 5

    cout<<test.find("abc")<<endl; // 3  it gives the pos of the first of the character in the string

    cout<<test.find("abc" , 5) << endl;// 7 starting searching from pos 5
    cout<<


return 0;
}
