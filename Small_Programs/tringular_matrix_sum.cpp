
#include <iostream>
using namespace std;

int main(){

int arr[100][100] = {0};
int n;
cin>>n;
int sum = 0;

    for(int i = 0;i<n;i++)
        for(int j =0;j<n;j++)
            cin>>arr[i][j];

    for(int i = 0;i<n;i++)
        for(int j =i;j<=n;j++){
           sum+=arr[i][j];
        }

cout<<"the upper triangle "<<sum<<endl;
sum = 0;
    for(int i = 0;i<n;i++)
        for(int j =0;j<=i;j++){
           sum+=arr[i][j];
        }

        cout<<"the lower triangle " <<sum;
}
