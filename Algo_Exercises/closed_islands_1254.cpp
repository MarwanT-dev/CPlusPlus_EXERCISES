#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> visited = vector<vector<int>>(100, vector<int>(100));

bool is_valid(int i , int j , int rows , int cols){
    if((i>=0&&i<rows)&&(j>=0&&j<cols))
        return 1;
    return 0;
}


bool is_closed(vector<vector<int>>& grid,int r,int c){
    vector<int> dr = {0,1,0,-1};
    vector<int> dc = {1,0,-1,0};

    int rows = grid.size();
    int cols = grid[0].size();

    visited[r][c] = 1;

    for(int i =0;i<4;i++){
        int next_r = r+dr[i] , next_c = c+dc[i];

        if(!is_valid(next_r,next_c,rows,cols))
            return 0;

        if(!visited[next_r][next_c]){
            visited[next_r][next_c] = 1;

            if(!grid[next_r][next_c]){
                if(!is_closed(grid,next_r,next_c))
                    return 0;
            }
            else
                continue;
        }


    }
    return 1 ;

}


int closedIsland(vector<vector<int>>& grid) {
    int cnt = 0;
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[0].size();j++){
            if(!visited[i][j]&&!grid[i][j])
                cnt+=is_closed(grid,i,j);
        }
    }
    return cnt;
}

int main() {
    vector<vector<int>> grid1 =
    {
               {{0,0,1},
               {1,1,0}}
    };

	cout<<closedIsland(grid1);
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

