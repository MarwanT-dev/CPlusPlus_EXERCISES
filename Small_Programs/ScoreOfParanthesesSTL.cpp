#include <bits/stdc++.h>
using namespace std;


int main(){
string str;
int sum = 0 , product = 1;
stack<char> s;
cin>>str;
s.push(s[0]);
for(int i = 1;i<str.size();i++){
    if(str[i]==s.top()&&str[i]=='('){
        product*=2;
        s.push(str[i]);
    }
    else {
        sum++;
        s.pop();
    }

}
int res = 0;
cout<<(res+sum)*product;


return 0;
}
