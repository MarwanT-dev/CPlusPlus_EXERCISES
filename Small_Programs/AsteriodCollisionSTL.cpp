#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
        for(auto it = asteroids.begin()+1;it!=asteroids.end();){
            if(*it <0&& *(it-1)> 0&&asteroids.size()>1 )
            {
               if(abs(*it)>abs(*(it-1)))
                    {asteroids.erase(it-1);it = asteroids.begin()+1;continue;}

                else if(abs(*it)<abs(*(it-1)))
            {asteroids.erase(it);it = asteroids.begin()+1;continue;}

                else
                    {asteroids.erase(it-1,it+1);it = asteroids.begin()+1;continue;}
            }
            else if (asteroids.size()==0)break;
            else it++;


        }
        return asteroids;
    }

int main(){
vector <int > v{1,2,-1,-2};
for(auto i : asteroidCollision(v))
    cout<<i;

return 0;
}
