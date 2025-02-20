#include <iostream>
using namespace std;

int main()
{
    int depth ,rows, cols;
    cin>>depth>>rows>>cols;
    int val ;
    while(true){
        cin>>val;
        if(val==1)
        {   int d,r,c;
            cin>>d>>r>>c;
            cout<<c+r*cols+d*rows*cols;
        }
        else if (val==2)
        {
            int indx;
            cin>>indx;
            cout<<"depth "<<indx/(rows*cols)<<' ';
            cout<<"rows "<<(indx%=(rows*cols))/cols<<' ';
            cout<<"cols "<<indx%cols;


        }
    }

return 0;
}


