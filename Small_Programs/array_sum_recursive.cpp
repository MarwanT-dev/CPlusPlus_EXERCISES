#include <iostream>
using namespace std;

int arr_sum(int arr[],int len){//note the len will be zero indexed don't worry
    if(len ==0)
        return arr[0];
    return arr[len]+arr_sum(arr,len-1);
}


int main (){

    int len,arr[100];
    cin>>len;

    for(int i =0;i<len;i++)
        cin>>arr[i];

    cout<<arr_sum(arr,len-1);

return 0;
}
