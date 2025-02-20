#include <iostream>
using namespace std;

void right_max(int arr[],int len){
    if(len==0)
        return;
    arr[len-1] = max(arr[len],arr[len-1]);
    right_max(arr,len-1);


}



int main(){
    int len,arr[100];
    cin>>len;
    for(int i= 0;i<len;i++)
        cin>>arr[i];

    right_max(arr,len-1);

    for(int i= 0;i<len;i++)
        cout<<arr[i]<<' ';



return 0;
}
