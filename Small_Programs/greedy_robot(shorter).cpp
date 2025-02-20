
#include <iostream>
using namespace std;

int main() {  // the idea of the program is that the robot is starting from 0 0 and get the sum from its position and transfer from one position to another according the greatest neighbor in the four neighbours
    int row,col;
    cin>>row>>col;
    int arr[100][100] = {0};
    for(int i =0;i<row;i++)
        for(int j = 0;j<col;j++)
            cin>>arr[i][j];

    //here is the concept of direction array

    int di[3] = {0,1,1}; //di => direction of i
    int dj[3] = {1,0,1}; //dj=> direction of  j

    int i = 0 , j = 0 , sum = 0;
    while(i<row&&j<col)
    {
        sum+=arr[i][j]; //here to get the intial pos 0 0

        int next_val , best_i = -1 , best_j = -1;
        for(int d = 0;d<3;d++)
        {
            int ni = i + di[d] , nj = j + dj[d];
            if(ni<row&&nj<col)
            {
                if(best_i = -1 || next_val<arr[ni][nj])
                    next_val = arr[ni][nj] , best_i = ni ,best_j = nj;
            }
        }
        if(best_i == -1)
                break ;
        i = best_i , j =best_j;
    }
    cout<<sum;

    return 0;
}

