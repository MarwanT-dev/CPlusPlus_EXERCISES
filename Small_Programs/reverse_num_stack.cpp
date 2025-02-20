#include <bits/stdc++.h>
using namespace std;

int reverse_num(int num){
    stack<int>  s;

    while(num ){
        s.push(num%10), num/=10;
    }
    int tens = 1;//here's the trick that we made a counter begin with 1 and multiply it with ten every time ( power simulation )
    while(!s.empty()){
       num= s.top()*tens+num,tens*=10,s.pop();
    }
    return num;
}

int main(){
    cout<<reverse_num(345);



return 0;
}
