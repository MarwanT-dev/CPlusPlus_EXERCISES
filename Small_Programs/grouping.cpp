#include <iostream>
using namespace std;

int main() {
    string str;
    cin>>str;
    str += "$";//this for handling the last group


    int cnt = 1;


    int group_size = 1;//for the first letter
    bool is_first_group = 1;

    for(int i = 1;i<str.size();i++)
    {
        if(str[i-1]!=str[i])
        {
            if(!is_first_group)
                cout<<'_';
            cout<<str[i-1]<<cnt;
            is_first_group = 0;
            cnt = 0;
        }
        cnt++;
    }






    return 0;
}
