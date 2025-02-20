#include<iostream>
using namespace std;

void star_pryamid(int x)
{
    int static y = 0;
    if(y==x)
        return;
    for(int i = y;i<x;i++)
        cout<<"*";
    cout<<endl;
    star_pryamid(--x);
}



int main (){
star_pryamid( 6);

return 0;
}
