#include <iostream>
using namespace std;

int main() {
    string str;
    cin>>str;
    int len = str.size();
    int carry = 0;
    for(int i =0;i<len ;i++)
    {
        int digit = str[len-i-1]- '0';
        if (i<4)
            digit += 5;
        digit+=carry;
        if(digit>=10)
        {
            digit -= 10;
            carry = 1;         //carry += digit; here u r dumb sorry the will only be 1 why u take it the digit -=10
        }
        else
            carry = 0;//this for making sure that we don't add on an old carry
        str[len-i-1] = (digit + '0');
    }
    if(carry)
        cout<<carry;//or u can cout<<1;
    cout<<str;

    return 0;
}

