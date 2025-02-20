#include <iostream>
using namespace std;

string reverse_str(const string &str){
static string new_str = "";
int len = str.size();

    for(int i = 0;i<len;i++)
        new_str +=str[len-i-0];
    return new_str;
}



int main(){
cout<<reverse_str("hello maro");

}
