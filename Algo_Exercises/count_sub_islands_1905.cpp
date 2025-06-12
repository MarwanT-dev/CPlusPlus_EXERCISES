#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> visited = vector<vector<int>>(500, vector<int>(500));
b
ool is_valid(int i , int j , int rows , int cols){
    if((i>=0&&i<rows)&&(j>=0&&j<cols))
        return 1;
    return 0;
}


int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&visited,int i , int j  ){

        if(!is_valid(i,j,grid2.size(),grid2[0].size())||visited[i][j]||(grid2[i][j]==0&&grid1[i][j]==0)||(grid2[i][j]-grid1[i][j]==-1)){
            return 0;
        }
        if((grid2[i][j]-grid1[i][j])==1)
            return -1 ;
        visited[i][j] = 1;
        if(dfs(grid1,grid2,visited,i,j+1)==-1
        ||dfs(grid1,grid2,visited,i,j-1)==-1
        ||dfs(grid1,grid2,visited,i+1,j)==-1
        ||dfs(grid1,grid2,visited,i-1,j)==-1)
        return -1;
        return 1;
}


int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int cnt = 0;
    for(int i = 0;i<grid2.size();i++){
        for(int j =0 ; j<grid2[0].size();j++){
            if(!visited[i][j])
                cnt+=(dfs(grid2,grid1,visited,i,j)==1);
        }
    }
    return cnt;
}



int main() {
    vector<vector<int>> grid1 = {
    {1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1}
};
vector<vector<int>> grid2 = {
    {1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1},
    {0, 1, 0, 0, 0},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0}
};
	countSubIslands(grid1,grid2);
	return 0;
}

/*

6 7
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10

Output
Node 0 has neighbors: (to 5 cost 45)
Node 1 has neighbors: (to 4 cost 60)
Node 2 has neighbors: (to 1 cost 10) (to 5 cost 20) (to 0 cost 77) (to 3 cost 33)
Node 3 has neighbors:
Node 4 has neighbors:
Node 5 has neighbors: (to 4 cost 10)

 */

