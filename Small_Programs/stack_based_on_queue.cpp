#include <iostream >
#include <queue>
#include <stack >
using namespace std;

struct Ourstack {
    queue<int>q;

void push(int val){


}
void pop(){
    if(!q.empty())
        q.pop();
}
int top(){
    return q.front();
}

bool empty(){
    return q.empty();
}



};





int main(){
    Ourstack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

while(!s.empty())
    cout<<s.top()<<' ' , s.pop();

stack<int> s1;

return 0;
}
