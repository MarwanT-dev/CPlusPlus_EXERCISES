#include <iostream>
using namespace std;

int main()
{
    int row, col,k;
    cin>>row>>col>>k;

    int di[4] = {-1,0,1,0};
    int dj[4] = {0,1,0,-1};

    int i = 0 , j = 0;
    for(int n =0;n<k;n++)
    {
        int d , steps;
        cin>>d>>steps;
        (i += di[d-1]*steps) , (j+=dj[d-1]*steps);
        if(i>=0)
            i%=row;
        else
        {
            i%=row;
            i+=row;
        }
        if(j>=0)
            j%=col;
        else
        {
            j%=col;
            j+=col;
        }
        cout<<i<<' ' <<j<<endl;


    }

return 0;
}

