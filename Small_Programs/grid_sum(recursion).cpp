#include <iostream >
using namespace std;

int grid_sum(int grid[100][100], int row ,int col , int ROW,int COL){
    if(row==ROW-1&&col==COL-1)
        return grid[0][0];

    int arr_row[3] = {0,1,1};
    int arr_col[3] = {1,0,1};

    int selected = -1 , best_row = -1 , best_col = -1;

    for(int i =0;i<3;i++){
        int n_row = row + arr_row[i];
        int n_col = col + arr_col[i];

        if(n_row<ROW&&n_col<COL)
        {
            if(grid[n_row][n_col]>selected||selected==-1)
                selected = grid[n_row][n_col] , best_row = n_row , best_col = n_col;
        }

    }
    return selected + grid_sum(grid,best_row,best_col,ROW,COL);


}


int main (){

    int row,col;
    cin>>row>>col;
    int arr[100][100];

    for(int i =0;i<row;i++)
        for(int j = 0;j<col;j++)
            cin>>arr[i][j];

    cout<<grid_sum(arr,0,0,row , col);

return 0;
}
