#include <iostream>
using namespace std;

int main() {
    string str,sub;
    cin>>str >>sub;
    int len = str.size() ;
    int arr[500] = {0};

    for(int i =0;i<sub.size();i++)
        for(int j = 0; j<len;j++)
        {
        if(sub[i]==str[j])
            arr[sub[i]] = j;
        }

    int last  = arr[sub[0]];
    for(int i = 'A';i<'Z';i++)
    {
        if(arr[i])
            {
                if(last>arr[i])
                {
                    cout<<"No";
                    return 0;
                }
               last = arr[i];
            }
    }
    cout<<"Yes";
    return 0;
}

