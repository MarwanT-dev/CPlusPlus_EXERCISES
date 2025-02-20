#include <iostream>
using namespace std;

void arr_increment(int arr[],int len,int const_len)
{
    if(len<0)
        return;
    cout<<arr[const_len-len]+const_len-len<<' ';
    arr_increment(arr,len-1,const_len);

}

int main (){
    int len, arr[100];
    cin>>len ;
    for(int i = 0;i<len;i++ )
        cin>>arr[i];
    arr_increment(arr,len-1,len-1);

return 0;
}
