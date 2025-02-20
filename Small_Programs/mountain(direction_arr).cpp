
#include <iostream>
using namespace std;

int main() {  // this the same of greedy robot but with 8 neighbours
    int row,col;
    cin>>row>>col;
    int arr[100][100] = {0};
    for(int i =0;i<row;i++)
        for(int j = 0;j<col;j++)
            cin>>arr[i][j];

    /*here is the concept of direction array
    1-make the direction arr
    2-make the loop for the direction as below:
        * make the next


    */
    int di[8] = {-1,-1,-1,0,0,1,1,1};
    int dj[8] = {-1,0,1,-1,1,-1,0,1};

    bool first = 1;
    int i = 0 , j = 0;
    while(i<row&&j<col)
    {
        int next_val  , best_i = -1 , best_j = -1;
        for(int d = 0;d<8;d++)
        {
            int ni = i + di[d] , nj = j + dj[d];

            if((ni<row&&ni>=0)&&(nj<col&&nj>=0))
            {
                if(first)
                {
                    next_val = arr[0][0];
                    first = 0;
                }

                if(best_i == -1 || next_val<arr[ni][nj])
                {
                   next_val = arr[ni][nj] , best_i = ni , best_j = nj;
                }
            }
        }
        if(best_i ==-1)
            break;
        i = best_i , j = best_j;

        cout<<i<<' '<<j;
    }


    return 0;
}


