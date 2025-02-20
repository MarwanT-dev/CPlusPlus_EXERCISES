

#include <iostream>
using namespace std;

int main(){//this isn't the true solution the true one is making two arr with opposite boundaries like 3 4  4 3 and then assign the vals

int arr[100][100] = {0};
int n,m;
cin>>n>>m;



    for(int i =0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>arr[i][j];

int q;
cin>>q;

for(int i = 0;i<q;i++)
{
    bool print = 1;
    int r1,r2;
    cin>>r1>>r2;
     for(int j =0;j<m;j++){
        if(arr[r1-1][j]>arr[r2-1][j]){
            print = 0;
            break;
        }
    }
    if(print)
        cout<<"Yes";
    else
        cout<<"No";
}

}
