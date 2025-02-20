#include <bits/stdc++.h>
using namespace std;

void test1(){
    vector<string> matrix {"mostafa","marwan","mohammed"};
    //string is 1F array of chars
    //what about vector <string > ?
    ///matrix of r rows , each one has dynamic columns
    ///mostafa
    /// marwan
    /// mohammed

    cout<<matrix.size()<<endl; // 3 rows

    int rows = matrix.size();
    for(int i =0;i<rows;++i){
        //Dynamic COlumn sizes: 7 3 2
        cout<<matrix[i].size()<<' ' ;
    }

}

void print(vector <vector <int > >&v2d){
    for(auto &row : v2d)
    {
        for(auto &col : row )
            cout<<col<<' ';
    }
    cout<<endl<<endl ;

}

void test2(){
    //2d array using vector

    vector<int > row(5,1); // 5 numbers each is 1

    vector<vector<int> > v2d(3, row); /// matrix 3 x 5

    print(v2d);

    int rows = v2d.size(); int cols = v2d[0].size();/// 3 5

    v2d[0][0] = 9;
    v2d[1].push_back(5);
    v2d[1].push_back(8);
    v2d[2].erase(v2d[2].begin());///important line loot at it

    print(v2d);




}


void test3(){
    vector<vector<vector<int>>> v3d(5,vector<vector<int>>(6,vector<int>(7)));

    /// this a matrix 3 x 6 x 7
    cout<<v3d.size()<<' ' << v3d[0].size()<<' ' << v3d[0][0].size()<<endl;

    for(int i =0 ;i<v3d.size();i++)
        print(v3d[i]);///print 2d vector

}
int main(){





return 0;
}
