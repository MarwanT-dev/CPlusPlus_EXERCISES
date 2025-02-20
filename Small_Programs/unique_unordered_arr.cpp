// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    bool first  = 1;
    int n;
    cin>>n;
    int arr[900] = {0};
    bool vis[901] = {0};


    for(int i =0;i<n ;i++)// the idea that u see if it first printed through the array of vis  if it not visited we print it and make it visited in the array
    {
        cin>>arr[i];
        if(!vis[arr[i]])
        {
            if(!first)
                cout<<',';
            first = 0;

            cout<<arr[i];
            vis[arr[i]] = 1;
        }


    }

    return 0;
}
