// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    char n;
    long k;
    cin>>n>>k;
    char a = (int(n)%97+(k%26))%26;
   // a+=int('a');

//    cout<<n%97<<' ' ;
//    cout<<k%25<<' ' ;
//    cout<<int(a)%25<<' ';

   cout<<char(a+'a');


    return 0;
}
