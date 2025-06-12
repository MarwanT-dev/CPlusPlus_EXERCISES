#include<iostream>
#include<vector>

#include<map>
using namespace std;



class Solution {


public:
    int original_color{},rows{},cols{};
    bool first = 1;
    vector<bool> visted;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(first){
            original_color = image[sr][sc];
            rows = image.size();
            cols = image[0].size();
            visted.resize(rows*cols,0);
            first = 0;
        }
        image[sr][sc] = color;
        visted[sr*cols+sc] = 1;
        if((sc-1>=0)&&(image[sr][sc-1]==original_color)&&(!visted[sr*cols+sc-1]))
            floodFill(image,sr,sc-1,color);

        if(sc+1<cols&&image[sr][sc+1]==original_color&&!visted[sr*cols+sc+1])
            floodFill(image,sr,sc+1,color);

        if(sr+1<rows&&image[sr+1][sc]==original_color&&!visted[(sr+1)*cols+sc])
            floodFill(image,sr+1,sc,color);

        if(sr-1>=0&&image[sr-1][sc]==original_color&&!visted[(sr-1)*cols+sc])
            floodFill(image,sr-1,sc,color);



return image;
    }
};



int main() {
    Solution s;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    s.floodFill(image,1,1,2);
    for(int row = 0;row<image.size();row++){
        for(int col = 0;col<image[row].size();col++)
            cout<<image[row][col]<<' ' ;
        cout<<endl;
    }

	return 0;
}
