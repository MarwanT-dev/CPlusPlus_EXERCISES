#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>res;
        for(int i =0;i<dist.size();i++)//t(n)
            res.push_back(double(dist[i])/speed[i]);

        sort(res.begin(),res.end());

        int cnt = 1;
        for(int i=1;i<res.size();i++){
            if(res[i]-i>0)
                cnt++;
            else
                break;
        }
        return cnt;
    }


int main()
{
    vector<int>dist {5,4,3,3,3};
    vector<int> speed {1,1,5,3,1};
    // .75  2
    cout<<eliminateMaximum(dist,speed);

    return 0;
}
