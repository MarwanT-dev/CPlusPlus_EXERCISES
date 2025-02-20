#include <iostream >
using namespace std;

int suffix_sum(int arr[],int len , int boundary){
    if(len==(boundary))
        return arr[len];
    return arr[len]+suffix_sum(arr,len-1,boundary );


}



int main(){
    int len,boundary,arr[100];
    cin>>len;

    for(int i= 0;i<len;i++)
        cin>>arr[i];
    cin>>boundary;

    cout<<suffix_sum(arr,len-1,boundary-1);



return 0;
}
