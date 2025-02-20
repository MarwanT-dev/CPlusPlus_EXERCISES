#include<iostream>
using namespace std;

int arr_max(int arr[],int len)
{
    if(len==0)
        return arr[0];
    return max(arr[len],arr_max(arr,len-1));
}




int main (){
    int len,arr[100];
    cin>>len;

    for(int i = 0;i<len;i++)
        cin>>arr[i];

    cout<<arr_max(arr,len-1);


return 0;
}



