#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[200] = {0};
    int rep[10] = {0};
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
        while(arr[i])
            {
                rep[arr[i]%10]++;
                arr[i]/=10;
            }
    }
    for(int i =0;i<10;i++)
    {
        cout<<i<<' '<<rep[i]<<endl;
    }

    return 0;
}
