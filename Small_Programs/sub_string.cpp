#include <iostream>
using namespace std;
int main() {
    string str,sub;
    cin>>str >>sub;



    int start = 0;
    for(int i =0;i<str.size();i++)
    {
     if(str[i]==sub[0])
     {
         start = i;
         break;
     }
    }

    int len = sub.size()+start;
    for(int i = start;i<len;i++)
    {
        if(str[i]!=sub[i])
        {
          cout<<"No";
          return 0;
        }

    }
    cout<<"Yes";
    return 0;
}

