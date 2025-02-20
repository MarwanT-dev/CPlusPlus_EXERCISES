#include <iostream>
using namespace std;

int power( int base, int expo)
{
    int  tmp = base;
    if(expo==0)
        return 1;


    return tmp*power(base,expo-1);
}




int main(){
int x,y;
cin>>x>>y;
cout<<power(x,y);


return 0;
}
