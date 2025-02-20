#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
vector<string> v;
string s;
int n;cin>>n;

while(n--){//we take the names in vector , in the lower loop we will loop on it
    cin>>s;v.push_back(s);
}

map<string , vector<string> > m;

for(auto name : v){
        string prefix = "";
    for(auto char_name : name){
        prefix+=char_name;
        m[prefix].push_back(name);
    }
}

int q ;cin>>q;
string prefix;
while(q--){
    cin>>prefix;
    for(auto i : m[prefix])
        cout<<i << ' ';
    cout<<endl;
}

return 0;
}
