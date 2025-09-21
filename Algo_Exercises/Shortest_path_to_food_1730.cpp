#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;



class Solution {


public:
    const int OO = 10000000;
bool is_valid(int i,int j, int rows,int cols){
    if((i>=0&&i<rows)&&(j>=0&&j<cols))
        return 1;
    return 0;

}
int BFS_v2(vector<vector<char>> &image, int r, int c) {

	vector<int> len(image[0].size()*image.size(), OO);
	queue<int> q;
	int R = image.size() , C = image[0].size();
	int start = r*C+c;
	q.push(start);
	len[start] = 0;

	for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
		while (sz--) {
			int cur = q.front();
			int cur_r = cur/C , cur_c = cur%C;
			q.pop();
			int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, 1, 0, -1};
			for(int i=0;i<4;i++){
                int next_r = cur_r+dr[i];
                int next_c = cur_c+dc[i];
                int neighbour = next_r*C+next_c;
                if (is_valid(next_r,next_c,R,C)&&len[neighbour] == OO&&image[next_r][next_c]!='X') {	// never visited
                    if(image[next_r][next_c]=='#')
                        return level+1;
                    q.push(neighbour);
                    len[neighbour] = cur;
                }
            }
        }
    }
return -1;
}



    int path_to_food(vector<vector<char>>grid) {
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++)
                if(grid[i][j]=='*')
                    return BFS_v2(grid,i,j);
        }


    }
};



int main() {
    vector<vector<char>> grid = {
        {'X','*'},
        {'#','X'}
    };
    Solution s;

    cout<<s.path_to_food(grid);
    return 0;
}
