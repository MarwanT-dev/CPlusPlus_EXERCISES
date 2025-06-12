#include<iostream>
#include<vector>
using namespace std;

//vector<vector<int>>visited(50,vector<int>(50));

class Solution {

vector<vector<int>>visited = vector<vector<int>>(50,vector<int>(50));
bool first =1;
int init_color ;

bool is_border(vector<vector<int>>& grid, int row, int col){
    int r = grid.size() , c = grid[0].size() ;
    if(row==0||row==(r-1)||col==0||col==(c-1))
        return 1;

    vector<int> dr = {0,1,0,-1};
    vector<int> dc = {1,0,-1,0};
    for(int i =0;i<4;i++)
        if(!visited[row+dr[i]][col+dc[i]]&&grid[row+dr[i]][col+dc[i]]!=init_color)
            return 1;
    return 0;
}

bool is_valid(int i , int j , int rows , int cols){
    if((i>=0&&i<rows)&&(j>=0&&j<cols))
        return 1;
    return 0;
}


public:

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    if(first){
        init_color = grid[row][col];
        first = 0;
    }

    if(is_border(grid,row,col))
        grid[row][col] = color;

    visited[row][col] = 1;
    vector<int> dr = {0,1,0,-1};
    vector<int> dc = {1,0,-1,0};

    int next_r,next_c;
    for(int i =0;i<4;i++){
        next_r = row+dr[i] , next_c = col+dc[i];

        if(is_valid(next_r,next_c,grid.size(),grid[0].size())&&!visited[next_r][next_c]&&grid[next_r][next_c]==init_color)
            colorBorder(grid,next_r,next_c,color);
    }
    return grid;

}


};
int main() {
    vector<vector<int>> grid{
        {1,1},{1,2}
    };
    Solution s1;s1.colorBorder(grid,0,0,3);

    for(int i =0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++)
            cout<<grid[i][j]<< ' ';
        cout<<endl;
    }

	return 0;
}
