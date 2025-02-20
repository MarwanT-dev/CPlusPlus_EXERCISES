#include <iostream>
using namespace std;

bool is_palindrome(int arr[],int x){

    for(int i = 0;i<x/2;i++)
        if(arr[x-1-i]!=arr[i])
        {
           cout<<"Not palindrome";
           return false;
        }
       cout<<"Palindrome ";
      return true;
}

int main (){
    int n;
    int arr[100] = {0};
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    is_palindrome(arr,n);

    return 0;
}
