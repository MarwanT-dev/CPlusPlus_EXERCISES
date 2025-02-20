#include <iostream>
using namespace std;

void set_powers(int arr[],int len = 5,int m=2)
{
    for(int i =0;i<len;i++)
    {
        int val = 1;
        for(int j = 0;j<i;j++)
            val*=m;
        arr[i] = val;

    }
    for(int i =0;i<len;i++)
        cout<<arr[i]<<' ';
}



int main(){
    int arr[100]  = {0};

    set_powers(arr,7,3);


 return 0;
}
