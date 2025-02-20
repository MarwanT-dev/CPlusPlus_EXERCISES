#include <iostream >
using namespace std;
void  arr_accumaltion (int arr[],int len){

    if(len==0)
        return;

    arr_accumaltion(arr,len-1);

    arr[len]+=arr[len-1];
}
int main(){
    int len,arr[100];
    cin>>len;

    for(int i = 0;i<len;i++)
        cin>>arr[i];

    arr_accumaltion(arr,len-1);

    for(int i = 0;i<len;i++)
        cout<<arr[i]<<' ';
return 0 ;
}
