#include <iostream>
using namespace std;

bool start_with(string input , string pattern,int pos)
{
    int len = pattern.size();
    for(int i = pos , j = 0 , steps = len ; steps-- ; i++,j++)
        if(input[i]!=pattern[j])
            return 0;

    return 1;
}

string replace_str(string input,string pattern , string to)
{
    string  new_string = "";
    for(int i =0;i<input.size();i++)
    {
        if(start_with(input,pattern,i))
            {
                new_string += to;
                i +=pattern.size();
            }
        else
        {
            for(int j = 0;j<pattern.size();j++)
            {
                new_string+=input[i];
            }
        }
    }
    return new_string;
}

int main (){

cout<<replace_str("aabcabaaad","aa","x");





return 0;
}
