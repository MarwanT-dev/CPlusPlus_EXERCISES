#include <iostream>
#include <stack>
#include <queue>
using namespace std;


void reverse_queue(queue<int>&q){
    stack<int> s;
    for(;!q.empty();){
        s.push(q.front());
        q.pop();
    }
    for(;!s.empty();){
        cout<<s.top()<<' ';
        s.pop();
    }




}

int main(){
queue <int > q;
for(int i = 0 ;i<6;i++)q.push(i);
reverse_queue(q);



return 0;
}
