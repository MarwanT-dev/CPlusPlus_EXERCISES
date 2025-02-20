
#include <iostream>

//the idea of the program will be next to the return 0;

using namespace std;

int main()  // any new inf will be noted with /**/
{
    int n;
    cin>>n;
    int arr[200];
    bool first = 1;
    int mn;

    for(int i = 0;i<n;i++)
        cin>>arr[i];

    for(int i = 0;i<n;i++)
    {
        for(int j= i+1;j<n;j++)
          {
            int tmp  = arr[i] + arr[j] +j-i;
            if(first||tmp < mn)
            {
                mn = tmp;
                first = 0;
            }
          }
    }

    cout<<mn;
    return 0;// this a brute force problem
}
