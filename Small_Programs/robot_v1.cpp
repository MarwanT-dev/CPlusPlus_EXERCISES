#include <iostream>
using namespace std;

int main(){

int arr[100][100]  = {0};
    int row,col;
    cin>>row>>col;

    for(int i = 0;i<row;i++)
        for(int j = 0;j<col;j++)
            cin>>arr[i][j];

    int robot = arr[0][0];

    int i,j = 0;//the two vars are zeros
    int sum = 0;

   while (i<row || j<col)//here we made a while loop not tow nested for loops cuz we won't go on every elem in the arr
   {
       sum+=arr[i][j];

       int best_i = -1,best_j = -1,best_val = arr[i][j];

       if(i+1<row)// the down elem
            best_val = arr[i+1][j] , best_i = i+1 , best_j = j;

       if(j+1<col){ // the right elem
        if(best_i == -1 || arr[i][j+1]>best_val)
            best_val = arr[i][j+1],best_i = i,best_j = j+1 ;
       }

       if(j+1<col&&i+1<row){ // the right elem
        if(best_i == -1 || arr[i+1][j+1]>best_val)
            best_val = arr[i+1][j+1],best_i = i+1,best_j = j+1 ;
       }

       if(best_i == -1)
            break;

        i = best_i , j = best_j;

        //sum+=arr[best_i][best_j];     if u made the sum here u will ignore the first elem in the arr[0][0]


   }
cout<<sum;


}
