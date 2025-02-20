#include <iostream>
using namespace std;

void is_palindrome(string str,int len,int const_len){
    if(str[len]!=str[const_len-len])
        {
            cout<<"no";
            return;
        }
    if(len==const_len/2)
        {
            cout<<"Yes";
            return;
        }
    is_palindrome(str,len-1,const_len);
}

int main(){
    int len;
    string str;

    cin>>str;

    len = str.size();

    is_palindrome(str,len-1,len-1);



return 0;
}
