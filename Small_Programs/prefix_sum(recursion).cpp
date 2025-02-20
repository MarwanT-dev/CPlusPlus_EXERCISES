#include <iostream >
using namespace std;

int prefix_sum(int arr[],int boundary){
    if(boundary==0)
        return arr[0];

    return arr[boundary]+prefix_sum(arr,boundary-1);

}




int main(){
    int len,boundary,arr[100];
    cin>>len;

    for(int i = 0;i<len;i++)
        cin>>arr[i];
    cin>>boundary;

    cout<<prefix_sum(arr,boundary-1);





return 0;
}
