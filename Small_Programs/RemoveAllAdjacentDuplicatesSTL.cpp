#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<char> v;
    string s ;cin>>s;
    for(auto i : s)
        v.push_back(i);
    for(auto it = v.begin()+1 ; it!=v.end();it++){
        if ( *it==*(it-1) ) {
            it = v.erase(it-1, it+1 );it--;
        }
    }

for(auto i : v)cout<<i;
return 0;
}
