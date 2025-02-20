#include <iostream>
using namespace std;

int static cnt = 0;
int sequence (int x){
    //cout<<x<< ' '; this was for the old problem
    cnt++;
    if (x==1)
    {
        cout<<cnt;
        return 1;
    }
    if(x%2==0)
        sequence(x/2);
    else
        sequence(3*x+1);


}


int main(){
    int n;
    cin>>n;
    sequence (n);

return 0 ;
}
