#include <iostream>
using namespace std;

void left_max(int arr[],int len){
    if(len==0)
        return;
    left_max(arr,len-1);//we call the function then put what we do after to make when the len goes from the first to the end
    arr[len] = max(arr[len],arr[len-1]);

}




int main(){
    int len,arr[100];
    cin>>len;
    for(int i = 0;i<len;i++)
        cin>>arr[i];
    left_max(arr,len-1);
    for(int i =0;i<len;i++)
        cout<<arr[i]<<' ';

 return 0;
}
