#include <bits/stdc++.h>
using namespace std;

int main(){
int arr[] = {1,2,3,4,5,6};

for(auto val : arr)
    cout<<val<<' ';
cout<<endl;

deque <int > q{1,2,3,4,5,6};

for(auto const val:q)
    cout<<val<<' ';
cout<<endl;

for(auto val : {1,2,3,4,5})
    cout<<val<<' ';
cout<<endl;

for(auto val : "marwan")
    cout<<val << ' ';
cout<<endl;





return 0;
}
