#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
struct cell {
    int sum , sub,c;


};
class Solution {


public:
    const int OO = 10000000;

int minimumOperations(vector<int>& arr, int start, int goal) {

	vector<bool> visited(1001,0);
	queue<int> q;

	q.push(start);

    cell idx;
	for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
		while (sz--) {
			int cur = q.front();

			q.pop();

            for(int i=0;i<arr.size();i++){
                ll operations[3] = {cur+arr[i],cur-arr[i],cur^arr[i]};
                for(int j=0;j<3;j++){
                    if(operations[j]==goal)
                        return level+1;
                    if(operations[j]>=0&&operations[j]<=1000&&visited[operations[j]]==0)
                        q.push(operations[j]),visited[operations[j]]=1;
                }
            }
        }
	}
	return -1;
}

};




int main() {
    vector<int> grid = {2,8,16};
    Solution s;

    cout<<s.minimumOperations(grid,0,1);
    return 0;
}
