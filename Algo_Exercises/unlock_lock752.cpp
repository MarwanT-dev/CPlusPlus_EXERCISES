
class Solution {
public:
vector<string> patterns(string &lock){
        vector<string> res;
        for(int i=0;i<4;i++){
            string temp = lock;
            if(lock[i]=='9'){
                temp[i] = '0';
                res.push_back(temp);
            }
            else{
                temp[i] = temp[i] +1;
                res.push_back(temp);
            }


            if(lock[i]=='0'){
                temp[i] = '9';
                res.push_back(temp);
            }
            else{
                temp[i] = lock[i] -1;
                res.push_back(temp);
            }

        }
    return res;

    }
int openLock(vector<string>& arr, string target) {
    if(find(arr.begin(),arr.end(),"0000")!=arr.end())
        return -1;

    map<string,bool> visited;
	queue<string> q;

	q.push("0000");
    visited["0000"] = 1;
    if(target=="0000")
        return 0;
	for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
		while (sz--) {
			string cur = q.front();

			q.pop();


            vector<string> operations = patterns(cur);
            for(int j=0;j<operations.size();j++){
                if(operations[j]==target)
                    return level+1;
                if(!visited.count(operations[j])&&find(arr.begin(),arr.end(),operations[j])==arr.end())
                    q.push(operations[j]),visited[operations[j]]=1;
            }

        }
	}
	return -1;
}
};
};
