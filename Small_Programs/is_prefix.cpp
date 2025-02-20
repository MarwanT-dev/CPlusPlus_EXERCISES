#include <iostream>
using namespace std;

bool is_prefix(string str,string prefix, int pos = 0 ){
    if(pos==prefix.size())
        return 1;

    if(str[pos]!=prefix[pos])
        return 0;
   return is_prefix(str,prefix,pos+1);


}



int main(){
    string str,prefix;
    cin>>str>>prefix;
cout<<is_prefix(str,prefix);


return 0;
}
