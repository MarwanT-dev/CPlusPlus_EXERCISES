#include <iostream>
using namespace std;

double arr_average(double arr[],int len,int const_len)
{
     if(len==0)
        return arr[0]/const_len;
     return (arr[len]/const_len) + arr_average(arr,len-1,const_len);
}

int main (){
    int len;
    double arr[100];
    cin>>len;
    for(int i= 0;i<len;i++)
        cin>>arr[i];

    cout<<arr_average(arr,len-1,len);


return 0;
}
